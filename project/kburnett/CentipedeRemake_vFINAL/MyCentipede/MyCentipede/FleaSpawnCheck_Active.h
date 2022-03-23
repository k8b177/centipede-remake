// FleaSpawnCheck_Active
// Katherine Burnett, September 2021

#ifndef _FleaSpawnCheck_Active
#define _FleaSpawnCheck_Active

#include "FleaSpawnCheck.h"

class FleaSpawner;

class FleaSpawnCheck_Active : public FleaSpawnCheck
{
public:
	FleaSpawnCheck_Active() = delete;
	FleaSpawnCheck_Active(const FleaSpawnCheck_Active&) = delete;
	FleaSpawnCheck_Active& operator= (const FleaSpawnCheck_Active&) = delete;
	~FleaSpawnCheck_Active() = default;

	FleaSpawnCheck_Active(FleaSpawner* pFleaSpawner);

	void CheckToSpawnFlea(int CurrentPlayerAreaMushroomCount, int PlayerAreaMushroomCountThreshold);
	
private:
	FleaSpawner* pFleaSpawner;

};
#endif _FleaSpawnCheck_Active