#include "ScorpionSpawner.h"

#include "GridInfo.h"
#include "ScorpionFactory.h"
#include "ScorpionSpawnCheck_Active.h"
#include "ScorpionSpawnCheck_Inactive.h"
#include "GameManager.h"

ScorpionSpawner::ScorpionSpawner(ActiveMoveMode* pActiveMoveMode, FrozenMoveMode* pFrozenMoveMode)
	:IsActive(ActiveStatus::Off), Speed(0), Frequency(0), myScorpionSpawnCheck(nullptr), pActiveMoveMode(pActiveMoveMode), pFrozenMoveMode(pFrozenMoveMode)
{
	pScorpionSpawnCheckActive = new ScorpionSpawnCheck_Active(this);
	pScorpionSpawnCheckInactive = new ScorpionSpawnCheck_Inactive();

	ScorpionFactory::SetScorpionSpawner(this);
	ScorpionFactory::SetGridManager(GameManager::GridManagerAccessor());
	
}

void ScorpionSpawner::InitializeWaveSettings(ActiveStatus status, int speed, float frequency)
{
	IsActive = status;
	Speed = speed;
	Frequency = frequency;

	if (IsActive == ActiveStatus::On)
		myScorpionSpawnCheck = pScorpionSpawnCheckActive;
	else
		myScorpionSpawnCheck = pScorpionSpawnCheckInactive;

	CheckSpawnNewScorpion();
}


void ScorpionSpawner::SpawnNewScorpion()
{
	//int spawnRow = GridInfo::GetRandomRow();
	int spawnRow = GridInfo::GetRandomScorpionSpawnRow();
	
	int direction = GridInfo::GetRandomRightOrLeft();

	int spawnCol;
	if (direction == -1)
		spawnCol = GridInfo::RIGHT_COLUMN + 1;
	else
		spawnCol = GridInfo::LEFT_COLUMN - 1;

	ScorpionFactory::CreateScorpion(GridInfo::GetVectPosAtColRow(spawnCol, spawnRow), Speed, spawnRow, spawnCol, direction);
}

void ScorpionSpawner::Alarm0()
{
	SpawnNewScorpion();
	CheckSpawnNewScorpion();
}

void ScorpionSpawner::StartTimer()
{
	SetAlarm(0, Frequency);
}

void ScorpionSpawner::CheckSpawnNewScorpion()
{
	myScorpionSpawnCheck->StartScorpionSpawnTimer();
}

ActiveMoveMode* ScorpionSpawner::GetActiveMoveMode()
{
	return pActiveMoveMode;
}
FrozenMoveMode* ScorpionSpawner::GetFrozenMoveMode()
{
	return pFrozenMoveMode;
}

void ScorpionSpawner::FreezeAllScorpions()
{
	ScorpionFactory::FreezeAllScorpions();
}

void ScorpionSpawner::DestroyAllActiveScorpions()
{
	ScorpionFactory::DestroyAllActiveScorpions();
}

ScorpionSpawner::~ScorpionSpawner()
{
	delete pScorpionSpawnCheckActive;
	delete pScorpionSpawnCheckInactive;
}