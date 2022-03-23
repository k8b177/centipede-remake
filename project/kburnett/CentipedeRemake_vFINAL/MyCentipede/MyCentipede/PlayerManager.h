// PlayerManager
// Katherine Burnett, October 2021

#ifndef _PlayerManager
#define _PlayerManager

#include "GameConstants.h"

class Player;
class PlayerController;

class PlayerManager
{
public:
	PlayerManager();
	PlayerManager(const PlayerManager&) = delete;
	PlayerManager& operator=(const PlayerManager&) = delete;
	~PlayerManager();

	void CreatePlayer();
	void CreatePlayerController();
	Player* GetCurrentPlayer();
	PlayerController* PlayerControllerAccessor();

private:
	Player* CurrentPlayer;
	PlayerController* myPlayerController;

};
#endif _PlayerManager
