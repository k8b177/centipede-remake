// Scorpion
// Katherine Burnett, September 2021

#include "Scorpion.h"

#include "GameConstants.h"
#include "ScorpionSpawner.h"
#include "GridManager.h"
#include "CmdScore.h"
#include "CmdSound.h"
#include "Mushroom.h"
#include "ExplosionFactory.h"

#include "ActiveMoveMode.h"
#include "FrozenMoveMode.h"

Scorpion::Scorpion()
{
	// Sprite Setup
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Scorpion"), 4, 1, GameConstants::FPS_ANIMATION);
	MainSprite.SetAnimation(0, 3);
	MainSprite.setScale(GameConstants::SPRITE_SCALE, GameConstants::SPRITE_SCALE);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);


	// Collider Setup
	bitmap = &ResourceManager::GetTextureBitmap("Scorpion");
	SetCollider(MainSprite, *bitmap);
}

void Scorpion::Initialize(sf::Vector2f pos, int speed, int row, int col, int direction, CmdScore* pCmdScore, CmdSound* pCmdSoundKill, GridManager* pGridManager, ScorpionSpawner* pScorpionSpawner)
{
	// Position Setup
	Pos = pos;
	MainSprite.setPosition(Pos);
	this->direction = direction;
	if (direction == 1)
	{
		RightColBound = GridInfo::RIGHT_COLUMN;
		LeftColBound = GridInfo::LEFT_COLUMN - 1;
		MainSprite.setScale(GameConstants::SPRITE_SCALE * -1, GameConstants::SPRITE_SCALE);
	}
	else
	{
		RightColBound = GridInfo::RIGHT_COLUMN + 1;
		LeftColBound = GridInfo::LEFT_COLUMN;
		MainSprite.setScale(GameConstants::SPRITE_SCALE, GameConstants::SPRITE_SCALE);
	}
	this->speed = speed;

	this->col = col;
	this->row = row;


	this->FramesToMoveOneCell = GridInfo::GetFramesToMoveOneCell(speed);

	frame = 1;

	this->pCmdScore = pCmdScore; // giving each scorpion a reference to the factory's command score
	this->pCmdSoundKill = pCmdSoundKill; // giving each scorpion a reference to the factory's command sound, Kill
	this->pGridManager = pGridManager; // giving each scorpion a reference to the factory's grid manager (used in Inspect)
	this->pScorpionSpawner = pScorpionSpawner; // giving each scorpion a reference to the factory's scorpion spawner (to set alarm when scorpion destroyed)

	pMoveMode = pScorpionSpawner->GetActiveMoveMode();

	RegisterCollision<Scorpion>(*this);
}

void Scorpion::Update()
{
	pMoveMode->MoveUpdate(this);
}

void Scorpion::MoveUpdate()
{
	MainSprite.Update();

	if (frame <= FramesToMoveOneCell)
	{
		Pos.x += speed * direction;
		frame++;
	}
	else
	{
		col += direction;
		Inspect();
		frame = 1;
	}

	MainSprite.setPosition(Pos);
}

void Scorpion::Freeze()
{
	pMoveMode = pScorpionSpawner->GetFrozenMoveMode();
}

void Scorpion::Inspect()
{

	if (col <= LeftColBound || col >= RightColBound)
	{
		//pScorpionSpawner->CheckSpawnNewScorpion();
		MarkForDestroy();
	}

	else
	{
		Mushroom* m = pGridManager->GetMushroomAt(row, col + direction);
		if (m != nullptr)
			m->Poison();
	}

}

void Scorpion::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void Scorpion::BulletHit()
{
	// play death animation
	pCmdScore->SendToManager();
	pCmdSoundKill->SendToManager();
	//pScorpionSpawner->CheckSpawnNewScorpion();

	ExplosionFactory::CreateOneCellExplosion(Pos);

	MarkForDestroy();
}

void Scorpion::Destroy()
{
	DeregisterCollision<Scorpion>(*this);
}