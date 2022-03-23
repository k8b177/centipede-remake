// TwoPlayerMode

#include "TwoPlayerMode.h"

#include "PlayerController.h"
#include "PlayerManager.h"
#include "HUDManager.h"
#include "GameManager.h"
#include "SoundManager.h"
#include "ScoreManager.h"

void TwoPlayerMode::ModeSetup(PlayerManager* pPlayerManager, HUDManager* pHUDManager, SoundManager* pSoundManager, ScoreManager* pScoreManager)
{
	PlayerController* pPlayerController = pPlayerManager->PlayerControllerAccessor();
	pPlayerController->SetCurrentControllerMode((ControllerMode*)pPlayerController->KeyboardStrategy);

	pHUDManager->SwitchToTwoPlayerHUD();

	GameManager::TurnStartGameCheckerOff();

	pSoundManager->SetOn();

	pScoreManager->SetInactive();

	// reset P1 & P2 scores and waves to score 0, wave 1
}

void TwoPlayerMode::ResetPlayerController(PlayerManager* pPlayerManager)
{
	PlayerController* pPlayerController = pPlayerManager->PlayerControllerAccessor(); // getting access to the PlayerController 
	pPlayerController->SetCurrentControllerMode((ControllerMode*)pPlayerController->KeyboardStrategy);
}