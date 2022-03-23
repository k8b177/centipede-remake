// WaveManager
// Katherine Burnett, October 2021

#ifndef _WaveManager
#define _WaveManager

#include "GameConstants.h"
#include "ActiveStatusEnum.h"


#include "WaveData.h"

class WaveManager
{
public:
	WaveManager() = default;
	WaveManager(const WaveManager&) = delete;
	WaveManager& operator=(const WaveManager&) = delete;
	~WaveManager() = default;

	WaveData WaveDataArray[GameConstants::WAVE_TOTAL_COUNT];

	// Sends out the correct wave settings to the critter spawners
	void LoadDataFromFile();
	WaveData GetWaveData(int wave_number);
};


#endif _WaveManager