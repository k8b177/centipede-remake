// GameScene
// Katherine Burnett, September 2021

#include "GameScene.h"
#include "../GameManager.h"
#include "../BulletFactory.h"

class GameManager;

#include "../Blaster.h"
#include "../Bullet.h"
#include "../Mushroom.h"
#include "../CentipedeHead.h"
#include "../CentipedeBody.h"
#include "../Scorpion.h"
#include "../Spider.h"
#include "../Flea.h"



void GameScene::Initialize()
{
	// Set up GameManager and GameMode (creates instance of singleton)
	GameManager::GameInitialize();


	// Setting background color
	WindowManager::SetBackgroundColor(sf::Color(0, 0, 0, 0));

	/// Setting Up Collisions ///

	// Bullet Collisions //
	CollisionTestPair<Bullet, Mushroom>();
	CollisionTestPair<Bullet, CentipedeHead>();
	CollisionTestPair<Bullet, CentipedeBody>();
	CollisionTestPair<Bullet, Scorpion>();
	CollisionTestPair<Bullet, Spider>();
	CollisionTestPair<Bullet, Flea>();

	// Mushroom Collision with Blaster //
	CollisionTestPair<Blaster, Mushroom>();

	// Blaster Collision with Critters //
	CollisionTestPair<Blaster, CentipedeHead>();
	CollisionTestPair<Blaster, CentipedeBody>();
	CollisionTestPair<Blaster, Flea>();
	CollisionTestPair<Blaster, Scorpion>();
	CollisionTestPair<Blaster, Spider>();



	// Starting Game
	//GameManager::StartGame();
}

void GameScene::Terminate()
{

}