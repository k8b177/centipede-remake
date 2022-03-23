#include "FleaSpawnCheck_Active.h"

#include "FleaSpawner.h"
#include "GridInfo.h"

FleaSpawnCheck_Active::FleaSpawnCheck_Active(FleaSpawner* pFleaSpawner)
{
	this->pFleaSpawner = pFleaSpawner;
}

void FleaSpawnCheck_Active::CheckToSpawnFlea(int CurrentPlayerAreaMushroomCount, int PlayerAreaMushroomCountThreshold)
{
	// Only Spawn if number of mushrooms in player area is below specified threshold
	if (CurrentPlayerAreaMushroomCount <= PlayerAreaMushroomCountThreshold)
		pFleaSpawner->SpawnFlea();
}