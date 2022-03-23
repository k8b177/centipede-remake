// Flea
// Katherine Burnett, September 2021

#include "Flea.h"
#include "GameConstants.h"

#include "MushroomFactory.h"
#include "CmdScore.h"
#include "CmdSound.h"
#include "GridManager.h"
#include "FleaSpawner.h"
#include "GridInfo.h"
#include "ExplosionFactory.h"

#include "ActiveMoveMode.h"
#include "FrozenMoveMode.h"

Flea::Flea()
{
	// Sprite Setup
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Flea"), 2, 2, GameConstants::FPS_ANIMATION);
	MainSprite.SetAnimation(0, 3);
	MainSprite.setScale(GameConstants::SPRITE_SCALE, GameConstants::SPRITE_SCALE);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 4.0f, MainSprite.getTextureRect().height / 4.0f);


	// Collider Setup
	bitmap = &ResourceManager::GetTextureBitmap("Flea");
	SetCollider(MainSprite, *bitmap);

	this->row = GridInfo::TOP_ROW + 1;
	speed = GameConstants::FLEA_SPEED;
	this->FramesToMoveOneCell = GridInfo::GetFramesToMoveOneCell(speed);
}

void Flea::Initialize(sf::Vector2f pos, int col, float mushroomDropRate, CmdScore* pCmdScore, CmdSound* pCmdSoundKill, GridManager* pGridManager, FleaSpawner* pFleaSpawner)
{
	// Position Setup
	Pos = pos;
	MainSprite.setPosition(Pos);

	// reset speed
	speed = GameConstants::FLEA_SPEED;
	

	// Row/Col Setup
	this->col = col;
	this->row = GridInfo::TOP_ROW + 1;
	
	frame = 1;

	// DropRate
	this->dropRate = mushroomDropRate;


	// Score Setup
	this->pCmdScore = pCmdScore;

	// Sound Setup
	this->pCmdSoundKill = pCmdSoundKill;

	// GridManager & FleaSpawner reference Setup
	this->pGridManager = pGridManager;
	this->pFleaSpawner = pFleaSpawner;

	// Health Setup
	this->health = 0;

	// Register Collison
	RegisterCollision<Flea>(*this);

	pMoveMode = pFleaSpawner->GetActiveMoveMode();
}

void Flea::Update()
{
	pMoveMode->MoveUpdate(this);
}

void Flea::MoveUpdate()
{
	MainSprite.Update();

	if (frame <= FramesToMoveOneCell)
	{
		Pos.y += speed;
		frame++;
	}
	else
	{
		row -= 1;
		CheckBoundary(); // kill when offscreen
		CheckToPlaceMushroom();
		frame = 1;
	}

	MainSprite.setPosition(Pos);
}

void Flea::Freeze()
{
	pMoveMode = pFleaSpawner->GetFrozenMoveMode();
}

void Flea::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void Flea::BulletHit()
{
	this->health += 1;

	if (health > 1) // dead
	{
		// play death animation
		pCmdScore->SendToManager();
		pCmdSoundKill->SendToManager();
		pFleaSpawner->CheckSpawnNewFlea(pGridManager->GetPlayerAreaMushroomCount());
		ExplosionFactory::CreateOneCellExplosion(Pos);
		MarkForDestroy();
	}
	else // only been hit once, goes faster
	{
		speed += 2;
	}
}

void Flea::CheckToPlaceMushroom()
{
	if (DropMushroomCheck())
	{
		if (pGridManager->GetMushroomAt(row, col) == nullptr)
		{
			MushroomFactory::CreateMushroom(row, col);
		}
	}
}

bool Flea::DropMushroomCheck()
{
	return rand() % 100 < dropRate;
}

void Flea::CheckBoundary()
{
	if (row < 0)
		MarkForDestroy();
}

void Flea::Destroy()
{
	DeregisterCollision<Flea>(*this);
}