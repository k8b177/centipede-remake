// SpiderSpawnCheck
// Katherine Burnett, September 2021

#ifndef _SpiderSpawnCheck
#define _SpiderSpawnCheck

class SpiderSpawnCheck
{
public:
	SpiderSpawnCheck() = default;
	SpiderSpawnCheck(const SpiderSpawnCheck&) = delete;
	SpiderSpawnCheck& operator= (const SpiderSpawnCheck&) = default;
	~SpiderSpawnCheck() = default;

	virtual void StartSpiderSpawnTimer() = 0;

};
#endif _SpiderSpawnCheck