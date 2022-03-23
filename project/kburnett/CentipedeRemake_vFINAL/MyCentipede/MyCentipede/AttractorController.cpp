// AttractorController

#include "AttractorController.h"

#include "GameManager.h"
#include "Game Components/GameScene.h"

AttractorController::AttractorController()
{
	RegisterInput(InputFlags::KeyPressed);
}

AttractorController::~AttractorController()
{
	DeregisterInput();
}

void AttractorController::KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey)
{
	/*switch (k)
	{
	case GameConstants::START_1PLAYERMODE_KEY:
		SceneManager::ChangeScene(new GameScene(GameModeEnum::OnePlayer));
		break;
	case GameConstants::START_2PLAYERMODE_KEY:
		SceneManager::ChangeScene(new GameScene(GameModeEnum::OnePlayer));
		break;
	}*/
}

void AttractorController::Destroy()
{
	DeregisterInput();
}