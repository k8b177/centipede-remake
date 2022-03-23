#include "WaveDataParser.h"


#include "WaveData.h"

WaveDataParser::WaveDataParser(WaveManager* pWaveManager)
{
	// Initializing Counters
	CurrentWaveBeingProcessed = 1;
	CurrentLineBeingProcessed = 0;

	this->pWaveManager = pWaveManager;

	// Calling Parse Method
	Parse();
}

void WaveDataParser::Parse()
{
	// Opening "WaveData" File
	DataFile.open("WaveData.txt");


	if (DataFile.is_open())
	{
		// Loops through all wave sections
		while (CurrentWaveBeingProcessed <= GameConstants::WAVE_TOTAL_COUNT)
		{
			////////   new WAVE SECTION   /////
			WaveData WaveSection;

			// WAVE LINE //
			ParseWaveLine();
			// SCORPION ACTIVE LINE
			WaveSection.ScorpionActive = ParseLine_Active("ScorpionActive");
			// SCORPION SPEED LINE
			WaveSection.ScorpionSpeed = ParseLine_Int("ScorpionSpeed");
			// SCORPION FREQUENCY LINE
			WaveSection.ScorpionFrequency = ParseLine_Float("ScorpionFrequency");
			// SPIDER ACTIVE LINE
			WaveSection.SpiderActive = ParseLine_Active("SpiderActive");
			// SPIDER SPEED LINE
			WaveSection.SpiderSpeed = ParseLine_Int("SpiderSpeed");
			// SPIDER FREQUENCY LINE
			WaveSection.SpiderFrequency = ParseLine_Float("SpiderFrequency");
			// FLEA ACTIVE LINE
			WaveSection.FleaActive = ParseLine_Active("FleaActive");
			// FLEA PLAYER AREA MUSHROOM COUNT THRESHOLD
			WaveSection.FleaPlayerAreaMushroomCountThreshold = ParseLine_Int("FleaPlayerAreaMushroomCountThreshold");
			// FLEA MUSHROOM SPAWN PROBABILITY
			WaveSection.FleaMushroomSpawnProbability = ParseLine_Float("FleaMushroomSpawnProbability");
			// CENTIPEDE SPEED 
			WaveSection.CentipedeSpeed = ParseLine_Int("CentipedeSpeed");
			// CENTIPEDE LENGTH
			WaveSection.CentipedeLength = ParseLine_Int("CentipedeLength");
			// CENTIPEDE SOLO HEAD ACTIVE
			WaveSection.CentipedeSoloHeadActive = ParseLine_Active("CentipedeSoloHeadActive");
			// CENTIPEDE SOLO HEAD COUNT
			WaveSection.CentipedeSoloHeadCount = ParseLine_Int("CentipedeSoloHeadCount");
			// CENTIPEDE SOLO HEAD IN PLAYER AREA Active
			WaveSection.CentipedeSoloHeadInPlayerAreaActive = ParseLine_Active("CentipedeSoloHeadInPlayerAreaActive");
			// CENTIPEDE SOLO HEAD IN PLAYER AREA COUNT
			WaveSection.CentipedeSoloHeadInPlayerAreaCount = ParseLine_Int("CentipedeSoloHeadInPlayerAreaCount");
			

			// copying WaveSection data over to WaveDataArray in WaveManager
			pWaveManager->WaveDataArray[CurrentWaveBeingProcessed - 1] = WaveSection;

			// Checks if file ended before all wave info was written
			if (CurrentWaveBeingProcessed != GameConstants::WAVE_TOTAL_COUNT)
			{
				if (DataFile.eof())
					PrintError("DATA ERROR: Too few waves! Input more Wave Data");
				CheckBlankLine();
			}

			// increment wave counter
			CurrentWaveBeingProcessed++;
		}

		if (!DataFile.eof())
			PrintError("DATA ERROR: Too many waves! Wave Data should end");

	}
	else
	{
		ConsoleMsg::WriteLine("DATA ERROR: 'WaveData.txt' File not found"); // Error if file not found
		std::exit(1);
	}

	// close DataFile
	DataFile.close();

	// Delete Parser
	delete this;
}

void WaveDataParser::ParseWaveLine()
{
	GetNextLine(); // Getting next line
	std::string label = std::string("Wave"); // Setting label to "Wave"
	CheckLabel(label);

	std::string s = line.substr(label.length() + 2, MAX_DIGIT_COUNT); // Getting WaveNumber string
	int x; // int for storing wave number
	try {
		x = std::stoi(s); // Try to convert WaveNumber to int
	}
	catch (...)
	{
		PrintError("Wave Number is not an integer");
	}
	if (x != CurrentWaveBeingProcessed)
		PrintError("Wave Number is invalid.  Should be " + std::to_string(CurrentWaveBeingProcessed));
	line = ""; // Setting line to empty string
}

int WaveDataParser::ParseLine_Int(std::string WaveParameter)
{
	GetNextLine(); // Get next line
	CheckLabel(WaveParameter); // Check label

	//  Process Integer 
	std::string s = line.substr(WaveParameter.length() + 2, MAX_DIGIT_COUNT); // Get Integer from file as string
	int x; // int for storing speed
	try {
		x = std::stoi(s); // Try to convert Integer to int
	}
	catch (...)
	{
		PrintError(WaveParameter + " not an integer"); // Conversion to int failed, ERROR
	}
	ConsoleMsg::WriteLine("Setting Wave" + std::to_string(CurrentWaveBeingProcessed) + " " + WaveParameter + " Value = " + std::to_string(x)); // SET!!!
	line = ""; // Setting line to empty string
	return x;
}

float WaveDataParser::ParseLine_Float(std::string WaveParameter)
{
	GetNextLine(); // Get next line
	CheckLabel(WaveParameter); // Check label

	//  Process Float 
	std::string s = line.substr(WaveParameter.length() + 2, MAX_DIGIT_COUNT); // Get Float from file as string
	float f; // float for storing speed
	try {
		f = std::stof(s); // Try to convert Float to float
	}
	catch (...)
	{
		PrintError(WaveParameter + " Value not a float"); // Conversion to float failed, ERROR
	}
	ConsoleMsg::WriteLine("Setting Wave" + std::to_string(CurrentWaveBeingProcessed) + " " + WaveParameter + " Value = " + std::to_string(f)); // SET!!!
	line = ""; // Setting line to empty string
	return f;
	
}

ActiveStatus WaveDataParser::ParseLine_Active(std::string WaveParameter)
{
	GetNextLine(); // Getting next line
	CheckLabel(WaveParameter);

	int length = WaveParameter.length() + 2;
	if (line.compare(length, 2, std::string("On")) == 0) // Checking if SpiderActive Value string is "On"
	{
		ConsoleMsg::WriteLine("Setting Wave" + std::to_string(CurrentWaveBeingProcessed) + " " + WaveParameter + " Value = On"); // SET!!!
		line = ""; // Setting line to empty string
		return ActiveStatus::On;
	}
	else if (line.compare(length, 3, std::string("Off")) == 0) // Checking SpiderActive Value string is "Off"
	{
		ConsoleMsg::WriteLine("Setting Wave" + std::to_string(CurrentWaveBeingProcessed) + " " + WaveParameter + " Value = Off"); // SET!!!
		line = ""; // Setting line to empty string
		return ActiveStatus::Off;
	}
	else
	{
		PrintError(WaveParameter + " Value is invalid. Must be 'On' or 'Off'");
		return ActiveStatus::Invalid;
	}
}

void WaveDataParser::GetNextLine()
{
	std::getline(DataFile, line); // Get Wave Line
	CurrentLineBeingProcessed++; // Increment LineCounter
}

void WaveDataParser::CheckLabel(std::string CorrectLabel)
{
	std::string label = CorrectLabel;
	int lengthOfLabel = label.length();
	std::string s = line.substr(0, lengthOfLabel + 2); // Getting user Label
	if (s.compare(label + ": ") != 0) // Check user Label equal to CorrectLabel
		PrintError(CorrectLabel + "Label ('" + s + "') misformatted. Should be('" + CorrectLabel + ": ')");
}

void WaveDataParser::CheckBlankLine()
{
	GetNextLine();
	if (line.length() != 0)
		PrintError("Should have blank line");
}


void WaveDataParser::PrintError(std::string errorName)
{
	ConsoleMsg::WriteLine("DATA ERROR: " + errorName + " at Line " + std::to_string(CurrentLineBeingProcessed));
	ConsoleMsg::WriteLine("EXITING PROGRAM");
	std::exit(1);
}