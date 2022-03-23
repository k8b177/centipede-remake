// ScorpionSpawnCheck
// Katherine Burnett, September 2021

#ifndef _ScorpionSpawnCheck
#define _ScorpionSpawnCheck

class ScorpionSpawnCheck
{
public:
	ScorpionSpawnCheck() = default;
	ScorpionSpawnCheck(const ScorpionSpawnCheck&) = delete;
	ScorpionSpawnCheck& operator= (const ScorpionSpawnCheck&) = default;
	~ScorpionSpawnCheck() = default;

	virtual void StartScorpionSpawnTimer() = 0;

};
#endif _ScorpionSpawnCheck