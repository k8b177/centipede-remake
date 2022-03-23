// CentipedeSegment
// Katherine Burnett, September 2021

#include "CentipedeSegment.h"


#include "GameConstants.h"

#include "MoveFSM.h"
#include "CentipedeHeadFactory.h"

#include "CmdScore.h"
#include "CmdSound.h"

#include "ExplosionFactory.h"


CentipedeSegment::CentipedeSegment()
	:bitmap(nullptr), col(0), frame(1), NumFramesToMoveOneCell(16), pCmdScore(nullptr), pCmdSoundKill(nullptr), pCurrentState(nullptr), pSegmentAhead(nullptr), pSegmentBehind(nullptr), row(0), speed(1)
{
	
}

int CentipedeSegment::GetRow()
{
	return row;
}

int CentipedeSegment::GetCol()
{
	return col;
}

void CentipedeSegment::SetRow(int newRow)
{
	row = newRow;
}

void CentipedeSegment::SetCol(int newCol)
{
	col = newCol;
}

void CentipedeSegment::SetState(const MoveState* state)
{
	pCurrentState = state;
}

void CentipedeSegment::PassAlongInfo()
{
	if (pSegmentBehind != nullptr)
	{
		pSegmentBehind->PassAlongInfo();
		pSegmentBehind->SetState(pCurrentState);
		pSegmentBehind->SetRow(row);
		pSegmentBehind->SetCol(col);
	}
}

void CentipedeSegment::BulletHit()
{
	PlaceMushroom();
	Split();

	pCmdScore->SendToManager();
	pCmdSoundKill->SendToManager();
	ExplosionFactory::CreateOneCellExplosion(Pos);
	MarkForDestroy();
}

void CentipedeSegment::PlaceMushroom()
{
	// Place Mushroom at correct row, col according to segment's state
	pCurrentState->PlaceMushroomAhead(row, col);
}

void CentipedeSegment::Split()
{
	// Fixing links
	if (pSegmentAhead != nullptr) // if segment is not a head, update tail of last segment to point to null
		pSegmentAhead->pSegmentBehind = nullptr;

	if (pSegmentBehind != nullptr) // if segment is not the tail, create new centipede behind
	{ 
		CentipedeHeadFactory::CreateCentipedeHead(pSegmentBehind->speed, pSegmentBehind->frame, pSegmentBehind->row, pSegmentBehind->col, pSegmentBehind->pSegmentBehind, pSegmentBehind->pCurrentState);
		pSegmentBehind->MarkForDestroy(); // destroying the body segment, since a head is replacing it
	}
}
