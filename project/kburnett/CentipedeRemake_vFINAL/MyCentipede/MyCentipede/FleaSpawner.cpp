#include "FleaSpawner.h"

#include "FleaFactory.h"
#include "FleaSpawnCheck_Active.h"
#include "FleaSpawnCheck_Inactive.h"
#include "GridInfo.h"
#include "GameManager.h"

FleaSpawner::FleaSpawner(ActiveMoveMode* pActiveMoveMode, FrozenMoveMode* pFrozenMoveMode)
	:IsActive(ActiveStatus::Off), PlayerAreaMushroomCountThreshold(0), MushroomSpawnProbability(0), pActiveMoveMode(pActiveMoveMode), pFrozenMoveMode(pFrozenMoveMode)
{
	pFleaSpawnCheckActive = new FleaSpawnCheck_Active(this);
	pFleaSpawnCheckInactive = new FleaSpawnCheck_Inactive();
	myFleaSpawnCheck = pFleaSpawnCheckInactive;

	FleaFactory::SetFleaSpawner(this);
	FleaFactory::SetGridManager(GameManager::GridManagerAccessor());
}

void FleaSpawner::CheckSpawnNewFlea(int CurrentPlayerAreaMushroomCount)
{
	myFleaSpawnCheck->CheckToSpawnFlea(CurrentPlayerAreaMushroomCount, PlayerAreaMushroomCountThreshold);
}

void FleaSpawner::InitializeWaveSettings(ActiveStatus status, int playerAreaMushroomCountThreshold, float mushroomSpawnProbability)
{
	IsActive = status;
	PlayerAreaMushroomCountThreshold = playerAreaMushroomCountThreshold;
	MushroomSpawnProbability = mushroomSpawnProbability;

	if (IsActive == ActiveStatus::On)
		myFleaSpawnCheck = pFleaSpawnCheckActive;
	else
		myFleaSpawnCheck = pFleaSpawnCheckInactive;

	FleaFactory::SetCurrentMushroomSpawnProbability(MushroomSpawnProbability);
}

void FleaSpawner::SpawnFlea()
{
	int spawnRow = GridInfo::TOP_ROW + 1;
	int spawnCol = GridInfo::GetRandomColumn();

	FleaFactory::CreateFlea(GridInfo::GetVectPosAtColRow(spawnCol, spawnRow), spawnCol);
}

ActiveMoveMode* FleaSpawner::GetActiveMoveMode()
{
	return pActiveMoveMode;
}
FrozenMoveMode* FleaSpawner::GetFrozenMoveMode()
{
	return pFrozenMoveMode;
}

void FleaSpawner::FreezeAllFleas()
{
	FleaFactory::FreezeAllFleas();
}

void FleaSpawner::DestroyAllActiveFleas()
{
	FleaFactory::DestroyAllActiveFleas();
}

FleaSpawner::~FleaSpawner()
{
	delete pFleaSpawnCheckActive;
	delete pFleaSpawnCheckInactive;
}