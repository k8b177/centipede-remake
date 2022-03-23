// AttractorMode

#include "AttractorMode.h"

#include "PlayerManager.h"
#include "Player.h"
#include "PlayerController.h"
#include "HUDManager.h"
#include "GameManager.h"
#include "SoundManager.h"

void AttractorMode::ModeSetup(PlayerManager* pPlayerManager, HUDManager* pHUDManager, SoundManager* pSoundManager, ScoreManager* pScoreManager)
{

	PlayerController* pPlayerController = pPlayerManager->PlayerControllerAccessor(); // getting access to the PlayerController 
	pPlayerController->SetCurrentControllerMode((ControllerMode*)pPlayerController->AIStrategy); // setting PlayerController right now so i can't do anything - no movement.  Change to AI.
	
	pHUDManager->SwitchToAttractorHUD();
	
	GameManager::TurnStartGameCheckerOn();

	pPlayerManager->GetCurrentPlayer()->InitializeNewMushroomFieldData();

	pSoundManager->ClearQueue();
	pSoundManager->SetMuted();
}

void AttractorMode::ResetPlayerController(PlayerManager* pPlayerManager)
{
	PlayerController* pPlayerController = pPlayerManager->PlayerControllerAccessor(); // getting access to the PlayerController 
	pPlayerController->SetCurrentControllerMode((ControllerMode*)pPlayerController->AIStrategy);
}