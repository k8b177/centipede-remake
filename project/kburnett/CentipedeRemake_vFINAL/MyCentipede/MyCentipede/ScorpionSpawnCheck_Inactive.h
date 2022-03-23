// ScorpionSpawnCheck_Inactive
// Katherine Burnett, September 2021

#ifndef _ScorpionSpawnCheck_Inactive
#define _ScorpionSpawnCheck_Inactive

#include "ScorpionSpawnCheck.h"


class ScorpionSpawnCheck_Inactive : public ScorpionSpawnCheck
{
public:
	ScorpionSpawnCheck_Inactive() = default;
	ScorpionSpawnCheck_Inactive(const ScorpionSpawnCheck_Inactive&) = delete;
	ScorpionSpawnCheck_Inactive& operator= (const ScorpionSpawnCheck_Inactive&) = delete;
	~ScorpionSpawnCheck_Inactive() = default;

	void StartScorpionSpawnTimer() { /* do nothing, Spider is Off for this wave */ }

};
#endif _ScorpionSpawnCheck_Inactive