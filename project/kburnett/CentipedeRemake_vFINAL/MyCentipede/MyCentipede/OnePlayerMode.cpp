// OnePlayer Mode

#include "OnePlayerMode.h"

#include "PlayerController.h"
#include "PlayerManager.h"
#include "Player.h"
#include "HUDManager.h"
#include "GameManager.h"
#include "SoundManager.h"
#include "ScoreManager.h"

void OnePlayerMode::ModeSetup(PlayerManager* pPlayerManager, HUDManager* pHUDManager, SoundManager* pSoundManager, ScoreManager* pScoreManager)
{
	PlayerController* pPlayerController = pPlayerManager->PlayerControllerAccessor();
	pPlayerController->SetCurrentControllerMode((ControllerMode*)pPlayerController->KeyboardStrategy);

	pHUDManager->SwitchToOnePlayerHUD();

	pPlayerManager->GetCurrentPlayer()->InitializeNewMushroomFieldData();

	GameManager::TurnStartGameCheckerOff();

	pSoundManager->ClearQueue();
	pSoundManager->SetOn();

	pScoreManager->ClearQueue();
	pScoreManager->SetActive();

	pPlayerManager->GetCurrentPlayer()->SetScore(0);

	pPlayerManager->GetCurrentPlayer()->SetLives(GameConstants::PLAYER_LIVES_MAX);

	pPlayerManager->GetCurrentPlayer()->SetWaveNumber(1);
	pPlayerManager->GetCurrentPlayer()->SetExtraLifeCounter(0);
}

void OnePlayerMode::ResetPlayerController(PlayerManager* pPlayerManager)
{
	PlayerController* pPlayerController = pPlayerManager->PlayerControllerAccessor(); // getting access to the PlayerController 
	pPlayerController->SetCurrentControllerMode((ControllerMode*)pPlayerController->KeyboardStrategy);
}