// CentipedeBody
// Katherine Burnett, September 2021

#include "CentipedeBody.h"
#include "GameConstants.h"

#include "MoveFSM.h"

#include "ActiveMoveMode.h"
#include "FrozenMoveMode.h"

#include "CentipedeSpawner.h"

CentipedeBody::CentipedeBody()
{
	// Sprite Setup
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("CentipedeBody"), 8, 2, GameConstants::FPS_ANIMATION * 2.0f);
	MainSprite.SetAnimation(0, 7);
	MainSprite.setScale(GameConstants::SPRITE_SCALE * 2, GameConstants::SPRITE_SCALE * 2);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);

	// Collider Setup
	bitmap = &ResourceManager::GetTextureBitmap("CentipedeBody");
	SetCollider(MainSprite, *bitmap);
}

void CentipedeBody::Initialize(int speed, int currentFrame, int row, int col, const MoveState* moveState, CmdScore* pCmdScore, CmdSound* pCmdSoundKill, CentipedeSpawner* pCentipedeSpawner)
{
	// Speed/Frame Setup
	this->speed = speed;
	this->NumFramesToMoveOneCell = GridInfo::CELLSIZE / speed;
	this->frame = currentFrame;
	this->pCurrentState = moveState;

	// Row/Col and Position Setup
	this->row = row;
	this->col = col;
	this->CurrCellPos = GridInfo::GetVectPosAtColRow(col, row);
	this->Pos = CurrCellPos;
	MainSprite.setPosition(Pos);

	// Animation Setup
	MainSprite.SetFrame(0);

	// Score Setup
	this->pCmdScore = pCmdScore;
	this->pCmdSoundKill = pCmdSoundKill;

	this->pCentipedeSpawner = pCentipedeSpawner;
	pMoveMode = pCentipedeSpawner->GetActiveMoveMode();

	// Collider Setup
	RegisterCollision<CentipedeBody>(*this);
}

void CentipedeBody::Update()
{
	pMoveMode->MoveUpdate(this);
}

void CentipedeBody::MoveUpdate()
{
	MainSprite.Update();

	if (frame <= NumFramesToMoveOneCell)
	{
		Pos.x = CurrCellPos.x + (pCurrentState->GetMoveOffsets()[(frame * speed) - 1]).xOffset;
		Pos.y = CurrCellPos.y + (pCurrentState->GetMoveOffsets()[(frame * speed) - 1]).yOffset;
		MainSprite.setRotation((pCurrentState->GetMoveOffsets()[(frame * speed) - 1]).angle);
		MainSprite.setPosition(Pos);
		frame++;
	}
	else
	{
		CurrCellPos = Pos;
		frame = 1;
	}
}

void CentipedeBody::Freeze()
{
	pMoveMode = pCentipedeSpawner->GetFrozenMoveMode();
}

void CentipedeBody::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void CentipedeBody::Destroy()
{
	DeregisterCollision<CentipedeBody>(*this);
}