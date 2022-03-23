// GameEntityManager

#include "GameEntityManager.h"

#include "GridManager.h"
#include "BlasterSpawner.h"
#include "ScorpionSpawner.h"
#include "SpiderSpawner.h"
#include "FleaSpawner.h"
#include "CentipedeSpawner.h"
#include "MushroomFactory.h"

#include "GameManager.h"
#include "PlayerManager.h"

#include "ActiveMoveMode.h"
#include "FrozenMoveMode.h"


GameEntityManager::GameEntityManager()
	:myBlasterSpawner(nullptr), myCentipedeSpawner(nullptr), myFleaSpawner(nullptr), myScorpionSpawner(nullptr), mySpiderSpawner(nullptr), myGridManager(nullptr)
{
	pPlayerManager = GameManager::PlayerManagerAccessor();

	pActiveMoveMode = new ActiveMoveMode();
	pFrozenMoveMode = new FrozenMoveMode();
}


GameEntityManager::~GameEntityManager()
{
	delete myGridManager;
	delete myBlasterSpawner;
	//delete myCentipedeSpawner;

	delete pActiveMoveMode;
	delete pFrozenMoveMode;
}

void GameEntityManager::CreateEntities()
{
	// Creating GridManager
	myGridManager = new GridManager();

	// Create BlasterSpawner
	myBlasterSpawner = new BlasterSpawner();

	// Create CentipedeSpawner 
	myCentipedeSpawner = new CentipedeSpawner(pActiveMoveMode, pFrozenMoveMode);

	// Create SpiderSpawner
	mySpiderSpawner = new SpiderSpawner(pActiveMoveMode, pFrozenMoveMode);

	// Create ScorpionSpawner
	myScorpionSpawner = new ScorpionSpawner(pActiveMoveMode, pFrozenMoveMode);

	MushroomFactory::SetGridManager(myGridManager); // give MushroomFactory a reference to the grid manager

	// Create FleaSpawner
	myFleaSpawner = new FleaSpawner(pActiveMoveMode, pFrozenMoveMode);
	myGridManager->SetFleaSpawner(myFleaSpawner); // give my GridManager a reference to the spawner so it can check to spawn flea when mushrooms are removed
}

void GameEntityManager::FillField(Player* p)
{
	myGridManager->FillCurrentMushroomFieldFromPlayerData(p);
}

GridManager* GameEntityManager::GridManagerAccessor()
{
	return myGridManager;
}

void GameEntityManager::SendOutWaveDataToSpawners(WaveData waveData)
{
	myCentipedeSpawner->InitializeWaveSettings(waveData.CentipedeSpeed, waveData.CentipedeLength, waveData.CentipedeSoloHeadActive, 
		                          waveData.CentipedeSoloHeadCount, waveData.CentipedeSoloHeadInPlayerAreaActive, waveData.CentipedeSoloHeadInPlayerAreaCount);
	mySpiderSpawner->InitializeWaveSettings(waveData.SpiderActive, waveData.SpiderSpeed, waveData.SpiderFrequency);
	myScorpionSpawner->InitializeWaveSettings(waveData.ScorpionActive, waveData.ScorpionSpeed, waveData.ScorpionFrequency);
	myFleaSpawner->InitializeWaveSettings(waveData.FleaActive, waveData.FleaPlayerAreaMushroomCountThreshold, waveData.FleaMushroomSpawnProbability);
}

void GameEntityManager::CancelSpawnerAlarms()
{
	if (mySpiderSpawner->AlarmActive(0))
		mySpiderSpawner->AlarmCancel(0);

	if (myScorpionSpawner->AlarmActive(0))
		myScorpionSpawner->AlarmCancel(0);

	if (myCentipedeSpawner->AlarmActive(0))
		myCentipedeSpawner->AlarmCancel(0);
}

void GameEntityManager::SpawnBlaster()
{
	myBlasterSpawner->SpawnBlaster();
}

void GameEntityManager::FreezeAllEntities()
{
	mySpiderSpawner->FreezeAllSpiders();
	myScorpionSpawner->FreezeAllScorpions();
	myFleaSpawner->FreezeAllFleas();
	myCentipedeSpawner->FreezeAllCentipedes();
}

void GameEntityManager::DestroyAllActiveCritters()
{
	mySpiderSpawner->DestroyAllActiveSpiders();
	myScorpionSpawner->DestroyAllActiveScorpions();
	myFleaSpawner->DestroyAllActiveFleas();
	myCentipedeSpawner->DestroyAllActiveCentipedes();
}

void GameEntityManager::ResetBlasterPos()
{
	myBlasterSpawner->ResetBlasterPos();
}