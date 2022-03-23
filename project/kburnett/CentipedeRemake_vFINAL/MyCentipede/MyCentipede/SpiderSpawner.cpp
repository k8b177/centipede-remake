// Spider_Spawner
// Katherine Burnett, September 2021


#include "SpiderSpawner.h"


#include "GameConstants.h"
#include "SpiderFactory.h"
#include "GridInfo.h"
#include "SpiderSpawnCheck_Active.h"
#include "SpiderSpawnCheck_Inactive.h"
#include "GameManager.h"


SpiderSpawner::SpiderSpawner(ActiveMoveMode* pActiveMoveMode, FrozenMoveMode* pFrozenMoveMode)
	:pActiveMoveMode(pActiveMoveMode), pFrozenMoveMode(pFrozenMoveMode), Frequency(0.0f), IsActive(ActiveStatus::Off), Speed(1), mySpiderSpawnCheck(nullptr)
{
	pSpiderSpawnCheckActive = new SpiderSpawnCheck_Active(this);
	pSpiderSpawnCheckInactive = new SpiderSpawnCheck_Inactive();

	SpiderFactory::SetSpiderSpawner(this);
	SpiderFactory::SetGridManager(GameManager::GridManagerAccessor());
}

void SpiderSpawner::SpawnNewSpider()
{
	int spawnRow = GetSpiderRandomRow();
	int direction = GridInfo::GetRandomRightOrLeft();

	int spawnCol;
	if (direction == -1)
		spawnCol = GridInfo::RIGHT_COLUMN + 1;
	else
		spawnCol = GridInfo::LEFT_COLUMN - 1;

	SpiderFactory::CreateSpider(GridInfo::GetVectPosAtColRow(spawnCol, spawnRow), Speed, spawnRow, spawnCol, direction);
}

int SpiderSpawner::GetSpiderRandomRow()
{
	return rand() % (GameConstants::MAX_SPIDER_SPAWN_ROW - GameConstants::MIN_SPIDER_SPAWN_ROW + 1) + GameConstants::MIN_SPIDER_SPAWN_ROW;
}

void SpiderSpawner::InitializeWaveSettings(ActiveStatus status, int speed, float frequency)
{
	IsActive = status;
	Speed = speed;
	Frequency = frequency;

	if (IsActive == ActiveStatus::On)
		mySpiderSpawnCheck = pSpiderSpawnCheckActive;
	else
		mySpiderSpawnCheck = pSpiderSpawnCheckInactive;

	CheckSpawnNewSpider();
}

void SpiderSpawner::Alarm0()
{
	SpawnNewSpider();
}

void SpiderSpawner::StartTimer()
{
	SetAlarm(0, Frequency);
}

void SpiderSpawner::CheckSpawnNewSpider()
{
	mySpiderSpawnCheck->StartSpiderSpawnTimer();
}


ActiveMoveMode* SpiderSpawner::GetActiveMoveMode()
{
	return pActiveMoveMode;
}
FrozenMoveMode* SpiderSpawner::GetFrozenMoveMode()
{
	return pFrozenMoveMode;
}

void SpiderSpawner::FreezeAllSpiders()
{
	SpiderFactory::FreezeAllSpiders();
}

void SpiderSpawner::DestroyAllActiveSpiders()
{
	SpiderFactory::DestroyAllActiveSpiders();
}

SpiderSpawner::~SpiderSpawner()
{
	delete pSpiderSpawnCheckActive;
	delete pSpiderSpawnCheckInactive;
}