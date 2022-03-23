#ifndef _HUDManager
#define _HUDManager

#include "Game Components/TEAL/CommonElements.h"
#include "GameConstants.h"

class SpriteString;
class LeftJustificationMode;
class RightJustificationMode;
class CenterJustificationMode;
class PlayerHUDMode;
class P1HUDMode;
class P2HUDMode;
class DoNothingHUDMode;
class AwesomeFont;
class ScoreManager;
class GridManager;

class HUDManager
{
public:
	// Big Four
	HUDManager();
	HUDManager(const HUDManager&) = delete;
	HUDManager& operator=(const HUDManager&) = delete;
	~HUDManager();

	void Initialize(ScoreManager* pScoreManager);

	void HUDDraw();

	void SwitchToOnePlayerHUD();
	void SwitchToTwoPlayerHUD();
	void SwitchToAttractorHUD();

	void SetPlayerScore(int x);
	void SetPlayerLives(int lives);

	void SetHUDModeToP1();
	void SetHUdModeToP2();
	void SetHUDModeToDoNothing();

	void SetP1Score(int x);
	void SetP1Lives(int n);
	void SetP2Score(int x);
	void SetP2Lives(int n);
	void SetHighscoreTop(int x);

	void UpdateHighscoreEntries();
	

private:
	void CreateAllHUDElements();
	void CreateP1Score();
	void CreateP1Lives();
	void CreateP2Score();
	void CreateP2Lives();
	void CreateHighscoreTop();
	void CreateRemainingAttractorElements();
	sf::Vector2f GetTextPosAtColRow(int col, int row);

	std::string ConvertNLivesToSymbolString(int n);


	AwesomeFont* myfont;

	SpriteString* P1Score;
	SpriteString* P1Lives;
	SpriteString* HighscoreTop;
	SpriteString* P2Score;
	SpriteString* P2Lives;
	SpriteString* HighscoresLabel;
	SpriteString* OneCoinOnePlay;
	SpriteString* CreditsOne;
	SpriteString* BonusEvery;
	SpriteString* GameOver;
	SpriteString* Copyright;
	SpriteString* HighscoreEntries[GameConstants::NUM_HIGHSCORE_ENTRIES];

	std::list<SpriteString*> ActiveSpriteStrings;

	SpriteString* CurrentPlayerScore;
	SpriteString* CurrentLives;

	LeftJustificationMode* pLeftJustificationMode;
	RightJustificationMode* pRightJustificationMode;
	CenterJustificationMode* pCenterJustificationMode;

	PlayerHUDMode* CurrentPlayerHUDMode;
	P1HUDMode* pP1HUDMode;
	P2HUDMode* pP2HUDMode;
	DoNothingHUDMode* pDoNothingMode;

	ScoreManager* pScoreManager;
	GridManager* pGridManager;
};


#endif _HUDManager

