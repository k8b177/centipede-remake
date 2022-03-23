// Spider
// Katherine Burnett, September 2021

#include "Spider.h"

#include "GameConstants.h"
#include "SpiderSpawner.h"
#include "GridManager.h"
#include "CmdScore.h"
#include "CmdSound.h"
#include "Mushroom.h"
#include "ExplosionFactory.h"

#include "ActiveMoveMode.h"
#include "FrozenMoveMode.h"

Spider::Spider()
{
	// Sprite Setup
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Spider"), 4, 2, GameConstants::FPS_ANIMATION);
	MainSprite.SetAnimation(0, 7);
	MainSprite.setScale(GameConstants::SPRITE_SCALE * 2.0f, GameConstants::SPRITE_SCALE * 2.0f);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);

	// Collider Setup
	bitmap = &ResourceManager::GetTextureBitmap("Spider");
	SetCollider(MainSprite, *bitmap);
}


void Spider::Initialize(sf::Vector2f pos, int speed, int row, int col, int overallXDirection, CmdScore* pCmdScore, CmdSound* pCmdSoundKill, GridManager* pGridManager, SpiderSpawner* pSpiderSpawner)
{
	Pos = pos;
	MainSprite.setPosition(Pos);
	this->overallXDirection = overallXDirection;
	this->speed = speed;
	this->framesToMoveOneCell = GridInfo::CELLSIZE / speed;
	this->frame = 1;
	this->row = row;
	this->col = col;

	if (overallXDirection == 1)
	{
		RightColBound = GridInfo::RIGHT_COLUMN;
		LeftColBound = GridInfo::LEFT_COLUMN - 1;
	}
	else
	{
		RightColBound = GridInfo::RIGHT_COLUMN + 1;
		LeftColBound = GridInfo::LEFT_COLUMN;
	}

	xDirection = overallXDirection;
	destinationRow = ChooseNewRow();

	this->pCmdScore = pCmdScore;
	this->pCmdSoundKill = pCmdSoundKill;
	this->pGridManager = pGridManager;
	this->pSpiderSpawner = pSpiderSpawner;

	//pMoveMode = (CritterMoveMode*)pSpiderSpawner->GetActiveMoveMode();
	pMoveMode = pSpiderSpawner->GetActiveMoveMode();

	RegisterCollision<Spider>(*this);
}

void Spider::Update()
{
	pMoveMode->MoveUpdate(this);
}


void Spider::MoveUpdate()
{
	MainSprite.Update();

	if (frame <= framesToMoveOneCell) // Moving between cells
	{
		Pos.x += xDirection * speed;
		Pos.y += yDirection * speed;
		frame++;
	}
	else // Moved to new cell
	{
		// Updating Row & Column
		row += -1 * yDirection;
		col += xDirection;

		//Inspect (left/right boundary and mushroom check)
		Inspect();

		// if spider reached the destinationRow, change direction and get new destination row
		if (row == destinationRow)
		{
			ChangeDirection();
		}
		frame = 1; // reset frame
	}

	MainSprite.setPosition(Pos); // Set Position
}

void Spider::Freeze()
{
	pMoveMode = pSpiderSpawner->GetFrozenMoveMode();
}

void Spider::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void Spider::BulletHit()
{
	pCmdScore->SetSpiderPointer(this);
	pCmdScore->SendToManager();
	pCmdSoundKill->SendToManager();
	pSpiderSpawner->CheckSpawnNewSpider();
	ExplosionFactory::CreateOneCellExplosion(Pos);
	MarkForDestroy(); 
}

void Spider::Destroy()
{
	DeregisterCollision<Spider>(*this);
}

void Spider::ChangeDirection()
{
	destinationRow = ChooseNewRow();
	ChooseVerticalOrDiagonal();
}

int Spider::ChooseNewRow()
{
	// Get Random Row in Range
	int newRow = row;
	while (newRow == row)
	{
		newRow = rand() % (GameConstants::MAX_SPIDER_SPAWN_ROW - GameConstants::MIN_SPIDER_SPAWN_ROW + 1) + GridInfo::BOTTOM_ROW;
	}

	if (newRow < row) // Going Down
		yDirection = 1;
	else // Going Up
		yDirection = -1;

	return newRow;
}

void Spider::ChooseVerticalOrDiagonal()
{
	// Chooosing Vertical or Diagonal 
	if (rand() % 2 == 0) // Vertical
	{
		xDirection = 0;
	}
	else // Diagonal
	{
		xDirection = overallXDirection;
	}
}

void Spider::Inspect()
{
	if (col <= LeftColBound || col >= RightColBound)
	{
		pSpiderSpawner->CheckSpawnNewSpider();
		MarkForDestroy();
	}

	else
	{
		Mushroom* m = pGridManager->GetMushroomAt(row, col);
		if (m != nullptr)
			m->Eat();
	}
}

sf::Vector2f Spider::GetPos()
{
	return Pos;
}