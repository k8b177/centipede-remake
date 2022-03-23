// CentipedeHead
// Katherine Burnett, September 2021

#include "CentipedeHead.h"

#include "GameConstants.h"
#include "MoveFSM.h"
#include "CentipedeHeadFactory.h"
#include "CentipedeSpawner.h"

#include "ActiveMoveMode.h"
#include "FrozenMoveMode.h"

CentipedeHead::CentipedeHead()
{
	// Sprite Setup
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("CentipedeHead"), 8, 2, GameConstants::FPS_ANIMATION * 2);
	SetAnimationToNormal();
	MainSprite.setScale(GameConstants::SPRITE_SCALE * 2, GameConstants::SPRITE_SCALE * 2);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);

	// Collider Setup
	bitmap = &ResourceManager::GetTextureBitmap("CentipedeHead");
	SetCollider(MainSprite, *bitmap);

	// Ahead/Behind Setup
	pSegmentAhead = nullptr; // nothing ahead since head

}

void CentipedeHead::Initialize(int speed, int currentFrame, int row, int col, CentipedeSegment* nextSegment, const MoveState* moveState, CmdScore* pCmdScore, CmdSound* pCmdSoundKill, CentipedeSpawner* pCentipedeSpawner)
{
	// Speed and Frame Setup
	this->speed = speed;
	this->NumFramesToMoveOneCell = GridInfo::GetFramesToMoveOneCell(speed);
	this->frame = currentFrame;

	// Row/Col and Position Setup
	this->row = row;
	this->col = col;
	this->CurrCellPos = GridInfo::GetVectPosAtColRow(col, row);
	this->Pos = CurrCellPos;
	MainSprite.setPosition(Pos);

	// Stitching in links
	pSegmentBehind = nextSegment;
	if (nextSegment != nullptr)
		nextSegment->pSegmentAhead = this;

	// Animation Setup
	MainSprite.SetFrame(0);

	// State Setup
	pCurrentState = moveState;

	// Score Setup
	this->pCmdScore = pCmdScore;
	this->pCmdSoundKill = pCmdSoundKill;

	this->pCentipedeSpawner = pCentipedeSpawner;
	pMoveMode = pCentipedeSpawner->GetActiveMoveMode();

	// Collision Setup
	RegisterCollision<CentipedeHead>(*this);
}

void CentipedeHead::Update()
{
	pMoveMode->MoveUpdate(this);
}

void CentipedeHead::MoveUpdate()
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
		PassAlongInfo();
		pCurrentState = pCurrentState->GetNextState(this);
		frame = 1;
	}
}

void CentipedeHead::Freeze()
{
	pMoveMode = pCentipedeSpawner->GetFrozenMoveMode();
}

void CentipedeHead::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void CentipedeHead::BulletHit()
{
	CentipedeSegment::BulletHit();
	CentipedeHeadFactory::CheckCentipedeHeadCount();

	if (GridInfo::InPlayerArea(col, row))
	{
		pCentipedeSpawner->DecrementCurrentHeadsInPlayerArea();
		pCentipedeSpawner->CheckSpawnNewHead();
	}
}

void CentipedeHead::SetAnimationToPoison()
{
	MainSprite.SetAnimation(8, 11);
}

void CentipedeHead::SetAnimationToNormal()
{
	MainSprite.SetAnimation(0, 7);
}

void CentipedeHead::Destroy()
{
	DeregisterCollision<CentipedeHead>(*this);
}