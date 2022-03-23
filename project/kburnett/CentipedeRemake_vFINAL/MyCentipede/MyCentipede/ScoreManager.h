// ScoreManager

#ifndef _ScoreManager
#define _ScoreManager

#include <queue>
#include "ScoreEventsEnum.h"
#include "Game Components/TEAL/CommonElements.h"
#include "HighscoreEntry.h"

class CmdScore;
class CmdSound;
class Blaster;

class ProcessScoreMode;
class ProcessScoreModeActive;
class ProcessScoreModeInactive;

class PlayerManager;
class HUDManager;
class SoundManager;

class ScoreManager
{
public:
	// Big Four
	ScoreManager();
	ScoreManager(const ScoreManager&) = default;
	ScoreManager& operator= (const ScoreManager&) = default;
	~ScoreManager();

	void Initialize(PlayerManager* pPlayerManager, HUDManager* pHUDManager, SoundManager* pSoundManager);
	void SetDefaultHighscores();
	void ClearQueue();

	void AddScore(int val);
	void SendScoreCmd(CmdScore* c);
	void ProcessScores();
	void SetActive();
	void SetInactive();
	void UpdateHighscoreList();
	int GetHighscore();

	void ScoreUpdate();

	// List of Top 8 HighScores
	std::list<HighscoreEntry> HighscoreEntryList;

private:
	CmdScore* GetScoreCommand(ScoreEvents ev);

	// Score values;
	const int FleaDeath = 200;
	const int ScorpionDeath = 1000;
	const int MushroomDeath = 1;
	const int MushroomPoisonDeath = 2;
	const int MushroomRegen = 5;
	const int CentipedeHeadDeath = 100;
	const int CentipedeBodyDeath = 10;

	const int SpiderDeathFar = 900;
	const int SpiderDistFar = 200;
	const int SpiderDistFar_Squared = SpiderDistFar * SpiderDistFar;

	const int SpiderDeathMedium = 600;
	const int SpiderDistMedium = 100;
	const int SpiderDistMedium_Squared = SpiderDistMedium * SpiderDistMedium;

	const int SpiderDeathNear = 300;
	const int SpiderDistNear = 50;
	const int SpiderDistNear_Squared = SpiderDistNear * SpiderDistNear;

	// Current High Score
	int highscore;

	// Extralife counter
	int extraLifeCounter;
	CmdSound* pCmdExtraLifeSnd;

	// solo instances of concrete strategy patterns for ProcessScoreMode
	ProcessScoreModeActive* pProcessScoreModeActive;
	ProcessScoreModeInactive* pProcessScoreModeInactive;
	ProcessScoreMode* CurrentProcessScoreMode;

	// Manager pointers
	HUDManager* pHUDManager;
	PlayerManager* pPlayerManager;

	std::queue<CmdScore*> QueueCmds;

};

#endif _ScoreManager