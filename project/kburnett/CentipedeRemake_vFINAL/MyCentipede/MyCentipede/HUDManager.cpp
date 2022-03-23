#include "HUDManager.h"

#include "SpriteString.h"
#include "GameConstants.h"

#include "LeftJustificationMode.h"
#include "RightJustificationMode.h"
#include "CenterJustificationMode.h"
#include "P1HUDMode.h"
#include "P2HUDMode.h"
#include "DoNothingHUDMode.h"
#include "AwesomeFont.h"
#include "GridInfo.h"
#include "ScoreManager.h"
#include "GridManager.h"
#include "GameManager.h"

HUDManager::HUDManager()
	:Copyright(nullptr), CurrentLives(nullptr), CurrentPlayerHUDMode(nullptr), CurrentPlayerScore(nullptr), HighscoreEntries(), HighscoresLabel(nullptr), myfont(nullptr), P1Lives(nullptr),
	P1Score(nullptr), P2Lives(nullptr), P2Score(nullptr), pCenterJustificationMode(nullptr), pDoNothingMode(nullptr), pLeftJustificationMode(nullptr), pP1HUDMode(nullptr), pP2HUDMode(nullptr),
	pRightJustificationMode(nullptr), pScoreManager(nullptr), HighscoreTop(nullptr), OneCoinOnePlay(nullptr), CreditsOne(nullptr), BonusEvery(nullptr), GameOver(nullptr), pGridManager(nullptr)
{																		

}																			

void HUDManager::Initialize(ScoreManager* pScoreManager)
{
	this->pScoreManager = pScoreManager;

	myfont = new AwesomeFont();

	pLeftJustificationMode = new LeftJustificationMode();
	pRightJustificationMode = new RightJustificationMode();
	pCenterJustificationMode = new CenterJustificationMode();

	CurrentPlayerHUDMode  = nullptr;
	pP1HUDMode = new P1HUDMode();
	pP2HUDMode = new P2HUDMode();
	pDoNothingMode = new DoNothingHUDMode();

	pGridManager = GameManager::GridManagerAccessor();

	CreateAllHUDElements();
}

void HUDManager::CreateAllHUDElements()
{
	CreateP1Score();
	CreateP1Lives();
	CreateP2Score();
	CreateP2Lives();
	CreateHighscoreTop();
	CreateRemainingAttractorElements();
}

void HUDManager::HUDDraw()
{
	for (SpriteString* s : ActiveSpriteStrings)
	{
		s->Draw();
	}
}

void HUDManager::SwitchToOnePlayerHUD()
{
	ActiveSpriteStrings.clear();

	ActiveSpriteStrings.push_back(P1Score);
	ActiveSpriteStrings.push_back(P1Lives);
	ActiveSpriteStrings.push_back(HighscoreTop);

	// Removing all of the Attractor TextBlocks
	pGridManager->RemoveTextBlockFromField(HighscoresLabel->GetRightTextBlock());
	pGridManager->RemoveTextBlockFromField(HighscoresLabel->GetLeftTextBlock());
	pGridManager->RemoveTextBlockFromField(OneCoinOnePlay->GetRightTextBlock());
	pGridManager->RemoveTextBlockFromField(OneCoinOnePlay->GetLeftTextBlock());
	pGridManager->RemoveTextBlockFromField(CreditsOne->GetRightTextBlock());
	pGridManager->RemoveTextBlockFromField(CreditsOne->GetLeftTextBlock());
	pGridManager->RemoveTextBlockFromField(BonusEvery->GetRightTextBlock());
	pGridManager->RemoveTextBlockFromField(BonusEvery->GetLeftTextBlock());
	pGridManager->RemoveTextBlockFromField(Copyright->GetRightTextBlock());
	pGridManager->RemoveTextBlockFromField(Copyright->GetLeftTextBlock());
	for (int i = 0; i < GameConstants::NUM_HIGHSCORE_ENTRIES; i++)
	{
		pGridManager->RemoveTextBlockFromField(HighscoreEntries[i]->GetRightTextBlock());
		pGridManager->RemoveTextBlockFromField(HighscoreEntries[i]->GetLeftTextBlock());
	}

	SetP1Score(0);
	SetP1Lives(GameConstants::PLAYER_LIVES_MAX);
	SetHighscoreTop(pScoreManager->GetHighscore());

	SetHUDModeToP1(); // making sure the score and lives to update will be the ones on the left
}

void HUDManager::SwitchToTwoPlayerHUD()
{
	ActiveSpriteStrings.clear();

	ActiveSpriteStrings.push_back(P1Score);
	ActiveSpriteStrings.push_back(P1Lives);
	ActiveSpriteStrings.push_back(HighscoreTop);
	ActiveSpriteStrings.push_back(P2Lives);
	ActiveSpriteStrings.push_back(P2Score);

	// Removing all of the Attractor TextBlocks
	pGridManager->RemoveTextBlockFromField(HighscoresLabel->GetRightTextBlock());
	pGridManager->RemoveTextBlockFromField(HighscoresLabel->GetLeftTextBlock());
	pGridManager->RemoveTextBlockFromField(OneCoinOnePlay->GetRightTextBlock());
	pGridManager->RemoveTextBlockFromField(OneCoinOnePlay->GetLeftTextBlock());
	pGridManager->RemoveTextBlockFromField(CreditsOne->GetRightTextBlock());
	pGridManager->RemoveTextBlockFromField(CreditsOne->GetLeftTextBlock());
	pGridManager->RemoveTextBlockFromField(BonusEvery->GetRightTextBlock());
	pGridManager->RemoveTextBlockFromField(BonusEvery->GetLeftTextBlock());
	pGridManager->RemoveTextBlockFromField(Copyright->GetRightTextBlock());
	pGridManager->RemoveTextBlockFromField(Copyright->GetLeftTextBlock());
	for (int i = 0; i < GameConstants::NUM_HIGHSCORE_ENTRIES; i++)
	{
		pGridManager->RemoveTextBlockFromField(HighscoreEntries[i]->GetRightTextBlock());
		pGridManager->RemoveTextBlockFromField(HighscoreEntries[i]->GetLeftTextBlock());
	}

	SetHUDModeToP1(); // making sure the score and lives to update will be the ones on the left
}

void HUDManager::SwitchToAttractorHUD()
{
	ActiveSpriteStrings.clear();

	ActiveSpriteStrings.push_back(P1Score);
	ActiveSpriteStrings.push_back(HighscoreTop);

	ActiveSpriteStrings.push_back(HighscoresLabel);
	pGridManager->InsertTextBlockIntoField(HighscoresLabel->GetRightTextBlock());
	pGridManager->InsertTextBlockIntoField(HighscoresLabel->GetLeftTextBlock());

	ActiveSpriteStrings.push_back(OneCoinOnePlay);
	pGridManager->InsertTextBlockIntoField(OneCoinOnePlay->GetRightTextBlock());
	pGridManager->InsertTextBlockIntoField(OneCoinOnePlay->GetLeftTextBlock());

	ActiveSpriteStrings.push_back(CreditsOne);
	pGridManager->InsertTextBlockIntoField(CreditsOne->GetRightTextBlock());
	pGridManager->InsertTextBlockIntoField(CreditsOne->GetLeftTextBlock());

	ActiveSpriteStrings.push_back(BonusEvery);
	pGridManager->InsertTextBlockIntoField(BonusEvery->GetRightTextBlock());
	pGridManager->InsertTextBlockIntoField(BonusEvery->GetLeftTextBlock());

	ActiveSpriteStrings.push_back(Copyright);
	pGridManager->InsertTextBlockIntoField(Copyright->GetRightTextBlock());
	pGridManager->InsertTextBlockIntoField(Copyright->GetLeftTextBlock());

	for (int i = 0; i < GameConstants::NUM_HIGHSCORE_ENTRIES; i++)
	{
		ActiveSpriteStrings.push_back(HighscoreEntries[i]);
		pGridManager->InsertTextBlockIntoField(HighscoreEntries[i]->GetRightTextBlock());
		pGridManager->InsertTextBlockIntoField(HighscoreEntries[i]->GetLeftTextBlock());
	}

	SetP1Score(0);
	//SetHighscoreTop(10);

	SetHUDModeToDoNothing();
	
	// need to push back all the high scores and other text on attractor screen
}

void HUDManager::CreateP1Score()
{
	int col = GridInfo::LEFT_COLUMN + GameConstants::MAX_SCORE_SPACES - 1;
	int row = GridInfo::TOP_ROW + 1;
	sf::Vector2f LeftScoreOrigin = GetTextPosAtColRow(col, row);
	P1Score = new SpriteString(pRightJustificationMode, row, col, LeftScoreOrigin, myfont, false);
}

void HUDManager::CreateP1Lives()
{
	int col = GridInfo::LEFT_COLUMN + GameConstants::MAX_SCORE_SPACES;
	int row = GridInfo::TOP_ROW + 1;
	sf::Vector2f LeftLivesOrigin = GetTextPosAtColRow(col, row);
 	P1Lives = new SpriteString(pLeftJustificationMode, row, col, LeftLivesOrigin, myfont, false);
}

void HUDManager::CreateP2Lives()
{
	int col = GridInfo::RIGHT_COLUMN - GameConstants::MAX_SCORE_SPACES;
	int row = GridInfo::TOP_ROW + 1;
	sf::Vector2f RightLivesOrigin = GetTextPosAtColRow(col, row);
	P2Lives = new SpriteString(pRightJustificationMode, row, col, RightLivesOrigin, myfont, false);
}

void HUDManager::CreateP2Score()
{
	int col = GridInfo::RIGHT_COLUMN - GameConstants::MAX_SCORE_SPACES + 1;
	int row = GridInfo::TOP_ROW + 1;
	sf::Vector2f RightScoreOrigin = GetTextPosAtColRow(col, row);
	P2Score = new SpriteString(pLeftJustificationMode, row, col, RightScoreOrigin, myfont, false);
}

void HUDManager::CreateHighscoreTop()
{
	int col = GridInfo::RIGHT_COLUMN / 2;
	int row = GridInfo::TOP_ROW + 1;
	sf::Vector2f HighscoreOrigin = GetTextPosAtColRow(col, row);
	HighscoreTop = new SpriteString(pCenterJustificationMode, row, col, HighscoreOrigin, myfont, false);
	SetHighscoreTop(pScoreManager->GetHighscore());
}

void HUDManager::CreateRemainingAttractorElements()
{
	int middleColumn = GridInfo::RIGHT_COLUMN / 2;

	// Creating HighscoresLabel
	sf::Vector2f HighscoreLabelOrigin = GetTextPosAtColRow(middleColumn, GridInfo::TOP_ROW - 1);
	HighscoresLabel = new SpriteString(pCenterJustificationMode, GridInfo::TOP_ROW - 1, middleColumn, HighscoreLabelOrigin, myfont, true);
	HighscoresLabel->SetGlyphList("High Scores");
	HighscoresLabel->PositionTextBlocks();

	// Creating Copyright
	sf::Vector2f CopyrightOrigin = GetTextPosAtColRow(middleColumn, GridInfo::BOTTOM_ROW);
	Copyright = new SpriteString(pCenterJustificationMode, GridInfo::BOTTOM_ROW, middleColumn, CopyrightOrigin, myfont, true);
	Copyright->SetGlyphList("[1980 Atari");
	Copyright->PositionTextBlocks();

	// Creating HighscoreEntries
	int FirstHighscoreEntryRow = GridInfo::TOP_ROW - 2;
	int i = 0;
	for (HighscoreEntry h : pScoreManager->HighscoreEntryList)
	{
		HighscoreEntries[i] = new SpriteString(pCenterJustificationMode, FirstHighscoreEntryRow - i, middleColumn, GetTextPosAtColRow(middleColumn, FirstHighscoreEntryRow - i), myfont, true);
		HighscoreEntries[i]->SetGlyphList(std::to_string(h.score) + " " + h.name);
		HighscoreEntries[i]->PositionTextBlocks();
		i++;
	}

	// Creating OneCoinOnePlay
	int OneCoinOnePlayRow = FirstHighscoreEntryRow - GameConstants::NUM_HIGHSCORE_ENTRIES - 2;
	sf::Vector2f OneCoinOnePlayOrigin = GetTextPosAtColRow(middleColumn, OneCoinOnePlayRow);
	OneCoinOnePlay = new SpriteString(pCenterJustificationMode, OneCoinOnePlayRow, middleColumn, OneCoinOnePlayOrigin, myfont, true);
	OneCoinOnePlay->SetGlyphList("1 Coin 1 Play");
	OneCoinOnePlay->PositionTextBlocks();

	// Creating CreditsOne
	sf::Vector2f CreditsOneOrigin = GetTextPosAtColRow(middleColumn, OneCoinOnePlayRow - 1);
	CreditsOne = new SpriteString(pCenterJustificationMode, OneCoinOnePlayRow - 1, middleColumn, CreditsOneOrigin, myfont, true);
	CreditsOne->SetGlyphList("Credits 1");
	CreditsOne->PositionTextBlocks();

	// Creating BonusEvery
	sf::Vector2f BonusEveryOrigin = GetTextPosAtColRow(middleColumn, OneCoinOnePlayRow - 2);
	BonusEvery = new SpriteString(pCenterJustificationMode, OneCoinOnePlayRow - 2, middleColumn, BonusEveryOrigin, myfont, true);
	BonusEvery->SetGlyphList("Bonus Every " + std::to_string(GameConstants::EXTRALIFE_POINT_THRESHOLD));
	BonusEvery->PositionTextBlocks();

	// Creating GameOver
	sf::Vector2f GameOverOrigin = GetTextPosAtColRow(middleColumn, OneCoinOnePlayRow - 4);
	GameOver = new SpriteString(pCenterJustificationMode, OneCoinOnePlayRow - 4, middleColumn, GameOverOrigin, myfont, true);
	GameOver->SetGlyphList("Game Over");
	GameOver->PositionTextBlocks();
}

void HUDManager::UpdateHighscoreEntries()
{
	int i = 0;
	for (HighscoreEntry h : pScoreManager->HighscoreEntryList)
	{
		HighscoreEntries[i]->SetGlyphList(std::to_string(h.score) + " " + h.name);
		HighscoreEntries[i]->PositionTextBlocks();
		i++;
	}
}

sf::Vector2f HUDManager::GetTextPosAtColRow(int col, int row)
{
	sf::Vector2f v = GridInfo::GetVectPosAtColRow(col, row);
	//v.x -= myfont->CellWidth() / 2;
	v.y -= myfont->CellHeight() / 2;

	return v;
}

void HUDManager::SetPlayerScore(int x)
{
	CurrentPlayerHUDMode->SetPlayerScore(this, x);
}
void HUDManager::SetPlayerLives(int lives)
{
	CurrentPlayerHUDMode->SetPlayerLife(this, lives);
}


void HUDManager::SetP1Score(int x)
{
	P1Score->ClearGlyphList();
	P1Score->SetGlyphList(std::to_string(x));
}
void HUDManager::SetP1Lives(int n)
{
	P1Lives->ClearGlyphList();
	P1Lives->SetGlyphList(ConvertNLivesToSymbolString(n));
}
void HUDManager::SetP2Score(int x)
{
	P2Score->SetGlyphList(std::to_string(x));
}
void HUDManager::SetP2Lives(int n)
{
	P2Lives->SetGlyphList(ConvertNLivesToSymbolString(n));
}
void HUDManager::SetHighscoreTop(int x)
{
	HighscoreTop->SetGlyphList(std::to_string(x));
}

std::string HUDManager::ConvertNLivesToSymbolString(int n)
{
	n -= 1;
	std::string s = "";
	while (n > 0)
	{
		s = s.append("*");
		n--;
	}
	return s;
}

void HUDManager::SetHUDModeToP1()
{
	CurrentPlayerHUDMode = pP1HUDMode;
}

void HUDManager::SetHUdModeToP2()
{
	CurrentPlayerHUDMode = pP2HUDMode;
}

void HUDManager::SetHUDModeToDoNothing()
{
	CurrentPlayerHUDMode = pDoNothingMode;
}


HUDManager::~HUDManager()
{
	delete pLeftJustificationMode;
	delete pRightJustificationMode;
	delete pCenterJustificationMode;

	delete pP1HUDMode;
	delete pP2HUDMode;
	delete pDoNothingMode;

	delete P1Score;
	delete P1Lives;
	delete P2Score;
	delete P2Lives;
	delete HighscoreTop;
	delete HighscoresLabel;
	delete OneCoinOnePlay;
	delete CreditsOne;
	delete BonusEvery;
	delete GameOver;
	delete Copyright;

	for (int i = 0; i < GameConstants::NUM_HIGHSCORE_ENTRIES; i++)
		delete HighscoreEntries[i];

	delete myfont;
}
