// HeadSpawnCheck_Inactive

#ifndef _HeadSpawnCheck_Inactive
#define _HeadSpawnCheck_Inactive

#include "HeadSpawnCheck.h"

class HeadSpawnCheck_Inactive : public HeadSpawnCheck
{
public:
	HeadSpawnCheck_Inactive() = default;
	HeadSpawnCheck_Inactive(const HeadSpawnCheck_Inactive&) = delete;
	HeadSpawnCheck_Inactive& operator= (const HeadSpawnCheck_Inactive&) = default;
	~HeadSpawnCheck_Inactive() = default;

	void CheckToSpawnHead(int CurrentCount_HeadsInPlayerArea, int CentipedeSoloHeadInPlayerAreaCount) override
	{
		// do nothing HeadsInPlayerArea is inactive for this wave
	};

};
#endif _HeadSpawnCheck_Inactive