// ScorpionSpawnCheck_Active
// Katherine Burnett, September 2021

#ifndef _ScorpionSpawnCheck_Active
#define _ScorpionSpawnCheck_Active

#include "ScorpionSpawnCheck.h"

class ScorpionSpawner;

class ScorpionSpawnCheck_Active : public ScorpionSpawnCheck
{
public:
	ScorpionSpawnCheck_Active() = delete;
	ScorpionSpawnCheck_Active(const ScorpionSpawnCheck_Active&) = delete;
	ScorpionSpawnCheck_Active& operator= (const ScorpionSpawnCheck_Active&) = delete;
	~ScorpionSpawnCheck_Active() = default;

	ScorpionSpawnCheck_Active(ScorpionSpawner* pScorpionSpawner);

	void StartScorpionSpawnTimer();

private:
	ScorpionSpawner* pScorpionSpawner;

};
#endif _ScorpionSpawnCheck_Active