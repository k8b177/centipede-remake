// HeadSpawnCheck

#ifndef _HeadSpawnCheck
#define _HeadSpawnCheck

class HeadSpawnCheck
{
public:
	HeadSpawnCheck() = default;
	HeadSpawnCheck(const HeadSpawnCheck&) = delete;
	HeadSpawnCheck& operator= (const HeadSpawnCheck&) = default;
	~HeadSpawnCheck() = default;

	virtual void CheckToSpawnHead(int CurrentCount_HeadsInPlayerArea, int CentipedeSoloHeadInPlayerAreaCount) = 0;

};
#endif _HeadSpawnCheck