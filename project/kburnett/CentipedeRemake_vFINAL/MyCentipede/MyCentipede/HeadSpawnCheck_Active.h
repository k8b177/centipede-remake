// HeadSpawnCheck_Active

#ifndef _HeadSpawnCheck_Active
#define _HeadSpawnCheck_Active

#include "HeadSpawnCheck.h"

class CentipedeSpawner;

class HeadSpawnCheck_Active : public HeadSpawnCheck
{
public:
	HeadSpawnCheck_Active() = delete;
	HeadSpawnCheck_Active(const HeadSpawnCheck_Active&) = delete;
	HeadSpawnCheck_Active& operator= (const HeadSpawnCheck_Active&) = default;
	~HeadSpawnCheck_Active() = default;

	HeadSpawnCheck_Active(CentipedeSpawner* pCentipedeSpawner);

	void CheckToSpawnHead(int CurrentCount_HeadsInPlayerArea, int CentipedeSoloHeadInPlayerAreaCount) override;

private:
	CentipedeSpawner* pCentipedeSpawner;

};
#endif _HeadSpawnCheck_Active