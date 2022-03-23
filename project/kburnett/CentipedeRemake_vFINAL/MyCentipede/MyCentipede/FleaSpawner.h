// FleaSpawner
// Katherine Burnett, September 2021

#ifndef _FleaSpawner
#define _FleaSpawner

#include "Game Components/TEAL/CommonElements.h"
#include "ActiveStatusEnum.h"

class FleaSpawnCheck;
class FleaSpawnCheck_Inactive;
class FleaSpawnCheck_Active;

class ActiveMoveMode;
class FrozenMoveMode;

class FleaSpawner : GameObject
{
public:
	FleaSpawner() = delete;
	FleaSpawner(const FleaSpawner&) = delete;
	FleaSpawner& operator= (const FleaSpawner&) = delete;
	~FleaSpawner();

	FleaSpawner(ActiveMoveMode* pActiveMoveMode, FrozenMoveMode* pFrozenMoveMode);

	void CheckSpawnNewFlea(int CurrentPlayerAreaMushroomCount);
	void SpawnFlea();
	void InitializeWaveSettings(ActiveStatus status, int playerAreaMushroomCountThreshold, float mushroomSpawnProbability);
	void FreezeAllFleas();
	void DestroyAllActiveFleas();

	ActiveMoveMode* GetActiveMoveMode();
	FrozenMoveMode* GetFrozenMoveMode();

private:

	ActiveStatus IsActive;
	int PlayerAreaMushroomCountThreshold;
	float MushroomSpawnProbability;

	FleaSpawnCheck* myFleaSpawnCheck;
	FleaSpawnCheck_Active* pFleaSpawnCheckActive;
	FleaSpawnCheck_Inactive* pFleaSpawnCheckInactive;

	ActiveMoveMode* pActiveMoveMode;
	FrozenMoveMode* pFrozenMoveMode;

};

#endif _FleaSpawner