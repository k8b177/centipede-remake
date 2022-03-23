// SpiderSpawnCheck_Inactive
// Katherine Burnett, September 2021

#ifndef _SpiderSpawnCheck_Inactive
#define _SpiderSpawnCheck_Inactive

#include "SpiderSpawnCheck.h"

class SpiderSpawnCheck_Inactive : public SpiderSpawnCheck
{
public:
	SpiderSpawnCheck_Inactive() = default;
	SpiderSpawnCheck_Inactive(const SpiderSpawnCheck_Inactive&) = delete;
	SpiderSpawnCheck_Inactive& operator= (const SpiderSpawnCheck_Inactive&) = delete;
	~SpiderSpawnCheck_Inactive() = default;


	void StartSpiderSpawnTimer() { /* do nothing, Spider is Off for this wave */ }

};

#endif _SpiderSpawnCheck_Inactive