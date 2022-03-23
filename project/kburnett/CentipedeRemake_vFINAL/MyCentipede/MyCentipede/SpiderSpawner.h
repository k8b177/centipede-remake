// SpiderSpawner
// Katherine Burnett, September 2021

#ifndef _SpiderSpawner
#define _SpiderSpawner

#include "Game Components/TEAL/CommonElements.h"
#include "ActiveStatusEnum.h"


class SpiderSpawnCheck;
class SpiderSpawnCheck_Active;
class SpiderSpawnCheck_Inactive;

class ActiveMoveMode;
class FrozenMoveMode;


class SpiderSpawner : public GameObject
{
public:
	SpiderSpawner() = delete;
	SpiderSpawner(const SpiderSpawner&) = delete;
	SpiderSpawner& operator= (const SpiderSpawner&) = delete;
	~SpiderSpawner();

	SpiderSpawner(ActiveMoveMode* pActiveMoveMode, FrozenMoveMode* pFrozenMoveMode);

	void InitializeWaveSettings(ActiveStatus status, int speed, float frequency);
	void CheckSpawnNewSpider();
	void StartTimer();
	void FreezeAllSpiders();
	void DestroyAllActiveSpiders();

	ActiveMoveMode* GetActiveMoveMode();
	FrozenMoveMode* GetFrozenMoveMode();


private:
	int GetSpiderRandomRow();
	void SpawnNewSpider();
	virtual void Alarm0();

	SpiderSpawnCheck* mySpiderSpawnCheck;
	SpiderSpawnCheck_Active* pSpiderSpawnCheckActive;
	SpiderSpawnCheck_Inactive* pSpiderSpawnCheckInactive;

	ActiveMoveMode* pActiveMoveMode;
	FrozenMoveMode* pFrozenMoveMode;

	ActiveStatus IsActive;
	int Speed;
	float Frequency;
};

#endif _SpiderSpawner