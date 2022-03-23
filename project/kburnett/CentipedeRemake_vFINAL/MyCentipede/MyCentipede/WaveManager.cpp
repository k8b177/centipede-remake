// WaveManager
// Katherine Burnett, October 2021

#include "WaveManager.h"

#include "ScorpionSpawner.h"
#include "SpiderSpawner.h"
#include "FleaSpawner.h"
#include "CentipedeSpawner.h"

#include "WaveDataParser.h"

void WaveManager::LoadDataFromFile()
{
	// Create parser to parse file and load data into WaveDataArray
	new WaveDataParser(this);
}


WaveData WaveManager::GetWaveData(int wave_number)
{
	// Subtract 1 from the wave number to get the right index for accessing the arrays
	int index = wave_number - 1;
	return WaveDataArray[index];
}

