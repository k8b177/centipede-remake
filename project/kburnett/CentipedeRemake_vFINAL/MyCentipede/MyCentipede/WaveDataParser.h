// Wave Data Parser

#include <fstream>
#include "WaveManager.h"

#ifndef _WaveDataParser
#define _WaveDataParser

class WaveManager;

class WaveDataParser
{
public:
	WaveDataParser() = delete;
	WaveDataParser(const WaveDataParser&) = delete;
	WaveDataParser& operator=(const WaveDataParser&) = delete;
	~WaveDataParser() = default;

	WaveDataParser(WaveManager* pWaveManager);

private:
	WaveManager* pWaveManager;

	int CurrentWaveBeingProcessed = 1;
	int CurrentLineBeingProcessed;
	std::ifstream DataFile;
	std::string line;
	const int MAX_DIGIT_COUNT = 10;

	void Parse();
	void GetNextLine();
	void ParseWaveLine();
	int ParseLine_Int(std::string WaveParameter);
	ActiveStatus ParseLine_Active(std::string WaveParameter);
	float ParseLine_Float(std::string WaveParameter);
	void CheckLabel(std::string CorrectLabel);
	void CheckBlankLine();
	void PrintError(std::string errorName);
};

#endif _WaveDataParser
