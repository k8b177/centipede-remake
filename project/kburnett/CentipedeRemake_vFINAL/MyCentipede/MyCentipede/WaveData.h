#ifndef _WaveData
#define _WaveData

#include "ActiveStatusEnum.h"

struct WaveData
{
	ActiveStatus ScorpionActive;
	int ScorpionSpeed;
	float ScorpionFrequency;
	ActiveStatus SpiderActive;
	int SpiderSpeed;
	float SpiderFrequency;
	ActiveStatus FleaActive;
	int FleaPlayerAreaMushroomCountThreshold;
	float FleaMushroomSpawnProbability;
	int CentipedeSpeed;
	int CentipedeLength;
	ActiveStatus CentipedeSoloHeadActive;
	int CentipedeSoloHeadCount;
	ActiveStatus CentipedeSoloHeadInPlayerAreaActive;
	int CentipedeSoloHeadInPlayerAreaCount;

	WaveData& WaveData::operator=(const WaveData&);
};

#endif _WaveData
