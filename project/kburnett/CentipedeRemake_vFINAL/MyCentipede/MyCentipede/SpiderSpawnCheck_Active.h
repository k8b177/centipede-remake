// SpiderSpawnCheck_Active
// Katherine Burnett, September 2021

#ifndef _SpiderSpawnCheck_Active
#define _SpiderSpawnCheck_Active

#include "SpiderSpawnCheck.h"

class SpiderSpawner;

class SpiderSpawnCheck_Active : public SpiderSpawnCheck
{
public:
	SpiderSpawnCheck_Active() = delete;
	SpiderSpawnCheck_Active(const SpiderSpawnCheck_Active&) = delete;
	SpiderSpawnCheck_Active& operator= (const SpiderSpawnCheck_Active&) = delete;
	~SpiderSpawnCheck_Active() = default;

	SpiderSpawnCheck_Active(SpiderSpawner* pSpiderSpawner);

	void StartSpiderSpawnTimer();

private:
	SpiderSpawner* pSpiderSpawner;
};

#endif _SpiderSpawnCheck_Active