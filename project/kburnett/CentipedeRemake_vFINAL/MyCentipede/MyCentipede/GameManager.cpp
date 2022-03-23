// Game Manager


#include "HUD.h"
#include "MushroomRegen.h"
#include "SpiderFactory.h"
#include "ScorpionFactory.h"
#include "BulletFactory.h"

#include "AttractorMode.h"
#include "OnePlayerMode.h"
#include "TwoPlayerMode.h"
#include "StartGameCheckerOn.h"
#include "StartGameCheckerOff.h"
#include "GameEntityManager.h"
#include "WaveManager.h"
#include "HUDManager.h"
#include "GameManager.h"
#include "PlayerManager.h"
#include "ScoreManager.h"
#include "SoundManager.h"
#include "PlayerController.h"

#include "Player.h"


GameManager* GameManager::ptrInstance = nullptr;


GameManager& GameManager::Instance()
{
	if (!ptrInstance)
		ptrInstance = new GameManager();
	return *ptrInstance;
}

void GameManager::Update()
{
	// Do score manager and hud update in here?  So they don't have to be game objects
	CurrentStartGameChecker->CheckToStart();

	myScoreManager->ScoreUpdate();
	mySoundManager->SoundUpdate();
}

void GameManager::Draw()
{
	myHUDManager->HUDDraw();
}


void GameManager::Destroy()
{
	delete AttractorModeStrategy;
	delete OnePlayerModeStrategy;
	delete TwoPlayerModeStrategy;

	delete StartGameCheckerOnStrategy;
	delete StartGameCheckerOffStrategy;

	delete myPlayerManager;
	delete myEntityManager;
	delete myWaveManager;
	delete mySoundManager;
	delete myScoreManager;
	delete myHUDManager;
}

void GameManager::privTurnStartGameCheckerOn()
{
	CurrentStartGameChecker = StartGameCheckerOnStrategy;
}

void GameManager::privTurnStartGameCheckerOff()
{
	CurrentStartGameChecker = StartGameCheckerOffStrategy;
}

void GameManager::privGameInitialize()
{
	// creating solo instances of GameMode Concrete Strategies
	AttractorModeStrategy = new AttractorMode();
	OnePlayerModeStrategy = new OnePlayerMode();
	TwoPlayerModeStrategy = new TwoPlayerMode();

	// create solo instances of StartGameChecker Concrete Strategies
	StartGameCheckerOnStrategy = new StartGameCheckerOn();
	StartGameCheckerOffStrategy = new StartGameCheckerOff();

	// creating managers (constructors are all default, still need to call set up methods after)
	myPlayerManager = new PlayerManager();
	myEntityManager = new GameEntityManager();
	myWaveManager = new WaveManager();
	myScoreManager = new ScoreManager();
	myHUDManager = new HUDManager();
	mySoundManager = new SoundManager();

	// Set up for managers
	mySoundManager->Initialize();
	myPlayerManager->CreatePlayer();
	myEntityManager->CreateEntities();
	myPlayerManager->CreatePlayerController();
	myWaveManager->LoadDataFromFile();
	myScoreManager->Initialize(myPlayerManager, myHUDManager, mySoundManager);
	myHUDManager->Initialize(myScoreManager);

	SetGameMode(GameModeEnum::Attractor);
}

void GameManager::Start()
{
	Player* currPlayer = myPlayerManager->GetCurrentPlayer();
	myEntityManager->FillField(currPlayer);
	StartWave(currPlayer->GetWaveNumber());
}

void GameManager::privSetGameMode(GameModeEnum newGameMode)
{
	switch (newGameMode)
	{
	case GameModeEnum::Attractor:
		CurrentGameMode = AttractorModeStrategy;
		break;
	case GameModeEnum::OnePlayer:
		CurrentGameMode = OnePlayerModeStrategy;
		break;
	case GameModeEnum::TwoPlayer:
		CurrentGameMode = TwoPlayerModeStrategy;
		break;
	default:
		break;
	}

	myEntityManager->ResetBlasterPos();

	CurrentGameMode->ModeSetup(myPlayerManager, myHUDManager, mySoundManager, myScoreManager);
	Start();
}

GridManager* GameManager::privGridManagerAccessor()
{
	return myEntityManager->GridManagerAccessor();
}

PlayerManager* GameManager::privPlayerManagerAccessor()
{
	return myPlayerManager;
}

WaveData GameManager::GetWaveData(int wave_number)
{
	return myWaveManager->GetWaveData(wave_number);
}

void GameManager::SendOutWaveDataToSpawners(WaveData waveData)
{
	myEntityManager->SendOutWaveDataToSpawners(waveData);
}

void GameManager::privEndOfWaveCallback()
{
	myEntityManager->CancelSpawnerAlarms();
	myPlayerManager->GetCurrentPlayer()->IncrementWaveNumber();

	if (myPlayerManager->GetCurrentPlayer()->GetWaveNumber() > GameConstants::WAVE_TOTAL_COUNT)
	{
		End();
		return;
	}

	StartWave(myPlayerManager->GetCurrentPlayer()->GetWaveNumber());
}

void GameManager::privLossOfLifeCallback()
{
	// Decrement Current Player's Lives
	myPlayerManager->GetCurrentPlayer()->DecrementLives(); // in the player class, subtract 1 from player's lives
	myHUDManager->SetPlayerLives(myPlayerManager->GetCurrentPlayer()->GetLives()); // update HUD lives
	ConsoleMsg::WriteLine("Lives: " + std::to_string(myPlayerManager->GetCurrentPlayer()->GetLives()));

	PlayerController* pPlayerController = myPlayerManager->PlayerControllerAccessor();
	pPlayerController->SetCurrentControllerMode((ControllerMode*)pPlayerController->FrozenStrategy);

	// Freeze all enemies
	myEntityManager->CancelSpawnerAlarms();
	myEntityManager->FreezeAllEntities();

	// Create and start mushroom regeneration
	MushroomRegen* mR = new MushroomRegen(GameManager::GridManagerAccessor());
	mR->StartRegen();
}

void GameManager::privEndOfMushroomRegen()
{
	// Check for game over
	if (myPlayerManager->GetCurrentPlayer()->GetLives() == 0)
	{
		End();
		return;
	}

	// Spawn Blaster
	myEntityManager->SpawnBlaster();

	// Clear All Critters
	//myEntityManager->DestroyAllActiveCritters();

	CurrentGameMode->ResetPlayerController(myPlayerManager);
	
	// Start CurrentPlayer's wave
	StartWave(myPlayerManager->GetCurrentPlayer()->GetWaveNumber());
}


void GameManager::StartWave(int wave_number)
{
	// Clear All Critters
	myEntityManager->DestroyAllActiveCritters();

	SendOutWaveDataToSpawners(GetWaveData(wave_number));
	// would do color change here too
}

void GameManager::End()
{
	// update highscore list on HUD
	myScoreManager->UpdateHighscoreList();
	myEntityManager->SpawnBlaster();
	SetGameMode(GameModeEnum::Attractor);
}

