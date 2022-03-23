// FleaSpawnCheck
// Katherine Burnett, September 2021

#ifndef _FleaSpawnCheck
#define _FleaSpawnCheck

class FleaSpawnCheck
{
public:
	FleaSpawnCheck() = default;
	FleaSpawnCheck(const FleaSpawnCheck&) = delete;
	FleaSpawnCheck& operator= (const FleaSpawnCheck&) = default;
	~FleaSpawnCheck() = default;

	virtual void CheckToSpawnFlea(int CurrentPlayerAreaMushroomCount, int PlayerAreaMushroomCountThreshold) = 0;

};
#endif _FleaSpawnCheck