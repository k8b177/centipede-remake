// LoadAllResources.cpp
// Andre Berthiaume, June 2012
//
// The user fills the method with all resources that need loading

#include "ResourceManager.h"
#include "../GameScene.h"

void ResourceManager::LoadAllResources()
{
	SetStartScene(new GameScene());

	AddTexture("Blaster", "../../../../../../reference/Asset/Sprites/blaster.png");
	AddTexture("Mushroom", "../../../../../../reference/Asset/Sprites/mushroom.png");
	AddTexture("Bullet", "../../../../../../reference/Asset/Sprites/bullet.png");
	AddTexture("Scorpion", "../../../../../../reference/Asset/Sprites/scorpion.png");
	AddTexture("Spider", "../../../../../../reference/Asset/Sprites/spider.png");
	AddTexture("CentipedeHead", "../../../../../../reference/Asset/Sprites/centipede_head.png");
	AddTexture("Flea", "../../../../../../reference/Asset/Sprites/flea.png");
	AddTexture("CentipedeBody", "../../../../../../reference/Asset/Sprites/centipede_segment.png");
	AddTexture("FullSpriteSheet", "../../../../../../reference/Asset/Sprites/SPRITES.png");
	AddTexture("ExplosionOneCell", "../../../../../../reference/Asset/Sprites/spawn.png");
	AddTexture("ExplosionTwoCell", "../../../../../../reference/Asset/Sprites/death.png");

	AddTexture("Alphabet", "../../../../../../reference/Asset/Sprites/FONTwPLAYER.bmp");

	AddSound("BulletFire", "../../../../../../reference/Asset/Sounds/fire1.wav");
	AddSound("Scorpion", "../../../../../../reference/Asset/Sounds/scorpion_new.wav");
	AddSound("CentipedeFootstep", "../../../../../../reference/Asset/Sounds/newBeat.wav");
	AddSound("Spider", "../../../../../../reference/Asset/Sounds/spiderloop.wav");
	AddSound("CritterKill", "../../../../../../reference/Asset/Sounds/kill.wav");
	AddSound("FleaSpawn", "../../../../../../reference/Asset/Sounds/flea_new.wav");
	AddSound("PlayerDeath", "../../../../../../reference/Asset/Sounds/death.wav");
	AddSound("MushroomRegen", "../../../../../../reference/Asset/Sounds/bonus.wav");
	AddSound("ExtraLife", "../../../../../../reference/Asset/Sounds/extraLife.wav");
}

