#include "StartGameCheckerOn.h"

#include "Game Components/TEAL/CommonElements.h"
#include "GameManager.h"

void StartGameCheckerOn::CheckToStart()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1))
		GameManager::SetGameMode(GameModeEnum::OnePlayer);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2))
		GameManager::SetGameMode(GameModeEnum::TwoPlayer);
}