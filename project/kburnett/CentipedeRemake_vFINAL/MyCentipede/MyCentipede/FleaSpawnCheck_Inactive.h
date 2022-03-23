// FleaSpawnCheck_Inactive
// Katherine Burnett, September 2021

#ifndef _FleaSpawnCheck_Inactive
#define _FleaSpawnCheck_Inactive

#include "FleaSpawnCheck.h"

class FleaSpawnCheck_Inactive : public FleaSpawnCheck // singleton
{
public:
	FleaSpawnCheck_Inactive() = default;
	FleaSpawnCheck_Inactive(const FleaSpawnCheck_Inactive&) = delete;
	FleaSpawnCheck_Inactive& operator= (const FleaSpawnCheck_Inactive&) = delete;
	~FleaSpawnCheck_Inactive() = default;

	void CheckToSpawnFlea(int CurrentPlayerAreaMushroomCount, int PlayerAreaMushroomCountThreshold)
		{ /* do nothing, Flea is Off for this wave */ }

};
#endif _FleaSpawnCheck_Inactive