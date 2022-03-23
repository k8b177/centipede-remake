#include "CentipedeSpawner.h"
#include "CentipedeHead.h"
#include "CentipedeBody.h"
#include "GridInfo.h"
#include "CentipedeHeadFactory.h"
#include "CentipedeBodyFactory.h"
#include "MoveFSM.h"

#include "HeadSpawnCheck_Active.h"
#include "HeadSpawnCheck_Inactive.h"

CentipedeSpawner::CentipedeSpawner(ActiveMoveMode* pActiveMoveMode, FrozenMoveMode* pFrozenMoveMode)
	:pActiveMoveMode(pActiveMoveMode), pFrozenMoveMode(pFrozenMoveMode), CentipedeLength(1), CentipedeSoloHeadActive(ActiveStatus::Off), CentipedeSoloHeadCount(0),
	CentipedeSoloHeadInPlayerAreaActive(ActiveStatus::Off), CentipedeSoloHeadInPlayerAreaCount(0), CentipedeSpeed(1), CurrentCount_HeadsInPlayerArea(0)
{
	CentipedeHeadFactory::SetCentipedeSpawner(this);
	CentipedeBodyFactory::SetCentipedeSpawner(this);

	pHeadSpawnCheckActive = new HeadSpawnCheck_Active(this);
	pHeadSpawnCheckInactive = new HeadSpawnCheck_Inactive();

	myHeadSpawnCheck = pHeadSpawnCheckInactive;
}

void CentipedeSpawner::SpawnNewCentipedeAtTop(int length, int speed)
{
	int spawnRow = GridInfo::TOP_ROW + 1;
	int spawnCol = GridInfo::GetRandomColumn();

	const MoveState* firstHeadMoveState = GetRandCentipedeDirection_StartAtTop();
	

	CentipedeHead* newHead = CentipedeHeadFactory::CreateCentipedeHead(speed, 1, spawnRow, spawnCol, nullptr, firstHeadMoveState);
	CentipedeSegment* ahead = newHead;
	CentipedeBody* newBody = nullptr;
	for (int i = 1; i < length; i++)
	{
		newBody = CentipedeBodyFactory::CreateCentipedeBody(speed, 1, spawnRow + (i), spawnCol, firstHeadMoveState);
		newBody->pSegmentAhead = ahead;
		ahead->pSegmentBehind = newBody;
		ahead = newBody;
	}
	ahead->pSegmentBehind = nullptr;
	
}

void CentipedeSpawner::SpawnCentipedeSoloHeadAtTop(int row, int col)
{
	const MoveState* firstHeadMoveState = GetRandCentipedeDirection_StartAtTop();
	CentipedeHeadFactory::CreateCentipedeHead(CentipedeSpeed, 1, row, col, nullptr, firstHeadMoveState);
}

void CentipedeSpawner::SpawnCentipedeSoloHeadInPlayerArea()
{
	int spawnColumn;
	const MoveState* firstMoveState = GetRandCentipedeDirection_StartAtSide(spawnColumn);
	int spawnRow = GridInfo::GetRandomRowInPlayerArea();
	CentipedeHeadFactory::CreateCentipedeHead(CentipedeSpeed, 1, spawnRow, spawnColumn, nullptr, firstMoveState);
}

const MoveState* CentipedeSpawner::GetRandCentipedeDirection_StartAtTop()
{
	if (rand() % 2 == 0) // right
		return &MoveFSM::StatePoisonFallRight;
	else // left
		return &MoveFSM::StatePoisonFallLeft;
}

const MoveState* CentipedeSpawner::GetRandCentipedeDirection_StartAtSide(int& columnReturned)
{
	if (rand() % 2 == 0) // right
	{
		columnReturned = GridInfo::RIGHT_COLUMN + 1;
		return &MoveFSM::StateMoveLeftAndDownwards;
	}
	else // left
	{
		columnReturned = GridInfo::LEFT_COLUMN - 1;
		return &MoveFSM::StateMoveRightAndDownwards;
	}
}

void CentipedeSpawner::InitializeWaveSettings(int centipedeSpeed, int centipedeLength, ActiveStatus centipedeSoloHeadActive, int centipedeSoloHeadCount, ActiveStatus centipedeSoloHeadInPlayerAreaActive, int centipedeSoloHeadInPlayerAreaCount)
{
	CentipedeSpeed = centipedeSpeed;
	CentipedeLength = centipedeLength;
	CentipedeSoloHeadActive = centipedeSoloHeadActive;
	CentipedeSoloHeadCount = centipedeSoloHeadCount;
	CentipedeSoloHeadInPlayerAreaActive = centipedeSoloHeadInPlayerAreaActive;
	CentipedeSoloHeadInPlayerAreaCount = centipedeSoloHeadInPlayerAreaCount;

	CurrentCount_HeadsInPlayerArea = 0;

	SpawnNewCentipedeAtTop(CentipedeLength, CentipedeSpeed);

	if (CentipedeSoloHeadActive == ActiveStatus::On)
	{
		for (int i = 0; i < CentipedeSoloHeadCount; i++)
		{
			SpawnCentipedeSoloHeadAtTop(GridInfo::TOP_ROW + 1, GridInfo::GetRandomColumn());
		}
	}
	
	if (CentipedeSoloHeadInPlayerAreaActive == ActiveStatus::On)
	{
		myHeadSpawnCheck = pHeadSpawnCheckActive;
		SetAlarm(0, GameConstants::TIME_BEFORE_HEADS_IN_PLAYER_AREA_SPAWN);
	}
	else
	{
		myHeadSpawnCheck = pHeadSpawnCheckInactive;
	}
}

ActiveMoveMode* CentipedeSpawner::GetActiveMoveMode()
{
	return pActiveMoveMode;
}
FrozenMoveMode* CentipedeSpawner::GetFrozenMoveMode()
{
	return pFrozenMoveMode;
}

void CentipedeSpawner::FreezeAllCentipedes()
{
	CentipedeHeadFactory::FreezeAllCentipedeHeads();
	CentipedeBodyFactory::FreezeAllCentipedeBodies();
}

void CentipedeSpawner::DestroyAllActiveCentipedes()
{
	CentipedeHeadFactory::DestroyAllActiveCentipedeHeads();
	CentipedeBodyFactory::DestroyAllActiveCentipedeBodies();
}

void CentipedeSpawner::Alarm0()
{
	CurrentCount_HeadsInPlayerArea++;
	SpawnCentipedeSoloHeadInPlayerArea();
	CheckSpawnNewHead();
}

void CentipedeSpawner::DecrementCurrentHeadsInPlayerArea()
{
	CurrentCount_HeadsInPlayerArea--;
}

void CentipedeSpawner::CheckSpawnNewHead()
{
	myHeadSpawnCheck->CheckToSpawnHead(CurrentCount_HeadsInPlayerArea, CentipedeSoloHeadInPlayerAreaCount);
}

void CentipedeSpawner::Destroy()
{
	delete pHeadSpawnCheckActive;
	delete pHeadSpawnCheckInactive;
}