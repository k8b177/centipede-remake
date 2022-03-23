#include "WaveData.h"

WaveData& WaveData::operator=(const WaveData& other)
{
	ScorpionActive = other.ScorpionActive;
	ScorpionSpeed = other.ScorpionSpeed;
	ScorpionFrequency = other.ScorpionFrequency;
	SpiderActive = other.SpiderActive;
	SpiderSpeed = other.SpiderSpeed;
	SpiderFrequency = other.SpiderFrequency;
	FleaActive = other.FleaActive;
	FleaPlayerAreaMushroomCountThreshold = other.FleaPlayerAreaMushroomCountThreshold;
	FleaMushroomSpawnProbability = other.FleaMushroomSpawnProbability;
	CentipedeSpeed = other.CentipedeSpeed;
	CentipedeLength = other.CentipedeLength;
	CentipedeSoloHeadActive = other.CentipedeSoloHeadActive;
	CentipedeSoloHeadCount = other.CentipedeSoloHeadCount;
	CentipedeSoloHeadInPlayerAreaActive = other.CentipedeSoloHeadInPlayerAreaActive;
	CentipedeSoloHeadInPlayerAreaCount = other.CentipedeSoloHeadInPlayerAreaCount;

	return *this;
}