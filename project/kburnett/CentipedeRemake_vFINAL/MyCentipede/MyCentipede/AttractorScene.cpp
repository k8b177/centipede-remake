// AttractorScene

#include "AttractorScene.h"
#include "GameManager.h"

#include "GameModeEnum.h"

#include "AttractorController.h"

void AttractorScene::Initialize()
{
	// Remove Later, here to easily see I am in Attractor Mode
	WindowManager::SetBackgroundColor(sf::Color(255, 192, 192, 0));

	// SetGameModeEnum in GameManager, decides which concrete strategy to use
	GameManager::SetGameMode(GameModeEnum::Attractor);

	// Create AttractorController for detecting when to change scenes
	new AttractorController();
}

void AttractorScene::Terminate()
{
	
}