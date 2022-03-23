// PlayerManager

#include "PlayerManager.h"

#include "Player.h"
#include "GameMode.h"
#include "PlayerController.h"

PlayerManager::PlayerManager()
{

}

void PlayerManager::CreatePlayer()
{
	CurrentPlayer = new Player();
}

void PlayerManager::CreatePlayerController()
{
	myPlayerController = new PlayerController();
}

Player* PlayerManager::GetCurrentPlayer()
{
	return CurrentPlayer;
}

PlayerController* PlayerManager::PlayerControllerAccessor()
{
	return myPlayerController;
}

PlayerManager::~PlayerManager()
{
	delete CurrentPlayer;
}