// GameStart.cpp
// Andre Berthiaume, July 2019

#include "Game.h"

#include "../../MushroomFactory.h"
#include "../../BulletFactory.h"
#include "../../CentipedeHeadFactory.h"
#include "../../CentipedeBodyFactory.h"
#include "../../SpiderFactory.h"
#include "../../ScorpionFactory.h"
#include "../../FleaFactory.h"
#include "../../BlasterFactory.h"
#include "../../ExplosionFactory.h"
#include "../../SpiderScoreSpriteFactory.h"

void Game::GameEnd()
{
	MushroomFactory::Terminate();
	BulletFactory::Terminate();
	CentipedeHeadFactory::Terminate();
	CentipedeBodyFactory::Terminate();
	SpiderFactory::Terminate();
	ScorpionFactory::Terminate();
	FleaFactory::Terminate();
	BlasterFactory::Terminate();
	ExplosionFactory::Terminate();
	SpiderScoreSpriteFactory::Terminate();
}