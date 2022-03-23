// ScorpionSpawner
// Katherine Burnett, September 2021

#ifndef _ScorpionSpawner
#define _ScorpionSpawner

#include "Game Components/TEAL/CommonElements.h"
#include "ActiveStatusEnum.h"

class ScorpionSpawnCheck;
class ScorpionSpawnCheck_Active;
class ScorpionSpawnCheck_Inactive;

class ActiveMoveMode;
class FrozenMoveMode;

class ScorpionSpawner : public GameObject
{
public:
	ScorpionSpawner() = delete;
	ScorpionSpawner(const ScorpionSpawner&) = delete;
	ScorpionSpawner& operator= (const ScorpionSpawner&) = delete;
	~ScorpionSpawner();

	ScorpionSpawner(ActiveMoveMode* pActiveMoveMode, FrozenMoveMode* pFrozenMoveMode);

	void InitializeWaveSettings(ActiveStatus status, int speed, float frequency);
	void StartTimer();
	void CheckSpawnNewScorpion();
	void DestroyAllActiveScorpions();

	ActiveMoveMode* GetActiveMoveMode();
	FrozenMoveMode* GetFrozenMoveMode();
	void FreezeAllScorpions();
	

private:
	void SpawnNewScorpion();
	virtual void Alarm0();

	ScorpionSpawnCheck* myScorpionSpawnCheck;
	ScorpionSpawnCheck_Active* pScorpionSpawnCheckActive;
	ScorpionSpawnCheck_Inactive* pScorpionSpawnCheckInactive;

	ActiveMoveMode* pActiveMoveMode;
	FrozenMoveMode* pFrozenMoveMode;

	ActiveStatus IsActive;
	int Speed;
	float Frequency;
};

#endif _ScorpionSpawner