// GameStart.cpp
// Andre Berthiaume, July 2019

#include "Game.h"
#include "CommonElements.h"

#include "../../GridInfo.h"
#include "../../GameManager.h"

void Game::GameStart()
{
	WindowManager::SetWindowSize(GridInfo::CELLSIZE * GridInfo::COLUMNS,
							     GridInfo::CELLSIZE * (GridInfo::ROWS + 1));

	WindowManager::SetCaptionName("My Centipede");

	WindowManager::SetBackgroundColor(sf::Color(0, 0, 0, 0));
}