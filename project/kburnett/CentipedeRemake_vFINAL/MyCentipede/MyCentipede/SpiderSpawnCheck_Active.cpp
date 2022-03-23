#include "SpiderSpawnCheck_Active.h"

#include "SpiderSpawner.h"

SpiderSpawnCheck_Active::SpiderSpawnCheck_Active(SpiderSpawner* pSpiderSpawner)
	:pSpiderSpawner(pSpiderSpawner)
{

}

void SpiderSpawnCheck_Active::StartSpiderSpawnTimer()
{
	pSpiderSpawner->StartTimer();
}