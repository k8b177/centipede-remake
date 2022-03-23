#include "ScoreManager.h"

#include "CmdScoreValue.h"
#include "CmdScoreByDistance.h"

#include "Game Components/TEAL/CommonElements.h"
#include "PlayerManager.h"
#include "Player.h"
#include "GameManager.h"
#include "Blaster.h"
#include "HUD.h"

#include "ScorpionFactory.h"
#include "CentipedeHeadFactory.h"
#include "CentipedeBodyFactory.h"
#include "FleaFactory.h"
#include "SpiderFactory.h"
#include "MushroomFactory.h"
#include "BlasterFactory.h"

#include "ProcessScoreModeActive.h"
#include "ProcessScoreModeInactive.h"

#include "HUDManager.h"
#include "SoundManager.h"

#include "CmdSound.h"

ScoreManager::ScoreManager()
	:pProcessScoreModeActive(nullptr), pProcessScoreModeInactive(nullptr), pPlayerManager(nullptr), pHUDManager(nullptr), pCmdExtraLifeSnd(nullptr),
	highscore(0), extraLifeCounter(0), CurrentProcessScoreMode(nullptr)
{

}

void ScoreManager::Initialize(PlayerManager* pPlayerManager, HUDManager* pHUDManager, SoundManager* pSoundManager)
{
	this->pPlayerManager = pPlayerManager;
	this->pHUDManager = pHUDManager;
	ScorpionFactory::SetCmdScore(GetScoreCommand(ScoreEvents::ScorpionKilled));
	SpiderFactory::SetCmdScore(GetScoreCommand(ScoreEvents::SpiderKilled));
	FleaFactory::SetCmdScore(GetScoreCommand(ScoreEvents::FleaKilled));
	CentipedeHeadFactory::SetCmdScore(GetScoreCommand(ScoreEvents::CentipedeHeadKilled));
	CentipedeBodyFactory::SetCmdScore(GetScoreCommand(ScoreEvents::CentipedeBodyKilled));
	MushroomFactory::SetCmdScores(GetScoreCommand(ScoreEvents::MushroomPoisonKilled), GetScoreCommand(ScoreEvents::MushroomKilled), GetScoreCommand(ScoreEvents::MushroomRegen));

	pProcessScoreModeActive = new ProcessScoreModeActive;
	pProcessScoreModeInactive = new ProcessScoreModeInactive;

	CurrentProcessScoreMode = pProcessScoreModeInactive;

	extraLifeCounter = 0;
	pCmdExtraLifeSnd = pSoundManager->GetSoundCommand(SoundEvents::ExtraLife);

	SetDefaultHighscores();
}

void ScoreManager::SetDefaultHighscores()
{
	HighscoreEntryList.push_back(HighscoreEntry(700, "STU"));
	HighscoreEntryList.push_back(HighscoreEntry(100, "ABC"));
	HighscoreEntryList.push_back(HighscoreEntry(400, "JKL"));
	HighscoreEntryList.push_back(HighscoreEntry(200, "DEF"));
	HighscoreEntryList.push_back(HighscoreEntry(300, "GHI"));
	HighscoreEntryList.push_back(HighscoreEntry(500, "MNO"));
	HighscoreEntryList.push_back(HighscoreEntry(600, "PQR"));
	HighscoreEntryList.push_back(HighscoreEntry(800, "VWX"));

	highscore = 800;

	HighscoreEntryList.sort();
}

void ScoreManager::UpdateHighscoreList()
{
	HighscoreEntryList.push_back(HighscoreEntry(pPlayerManager->GetCurrentPlayer()->GetScore(), "NEW"));
	HighscoreEntryList.sort();
	HighscoreEntryList.pop_back();
	pHUDManager->UpdateHighscoreEntries();
}

CmdScore* ScoreManager::GetScoreCommand(ScoreEvents ev)
{
	CmdScore* pCmd = nullptr;
	ConsoleMsg::WriteLine("Score Manager: Constructing score command for ");

	switch (ev)
	{
	case ScoreEvents::FleaKilled:
		ConsoleMsg::WriteLine("FleaDeath");
		pCmd = new CmdScoreValue(FleaDeath, this);
		break;
	case ScoreEvents::ScorpionKilled:
		ConsoleMsg::WriteLine("ScorpionDeath");
 		pCmd = new CmdScoreValue(ScorpionDeath, this);
		break;
	case ScoreEvents::MushroomKilled:
		ConsoleMsg::WriteLine("MushroomDeath");
		pCmd = new CmdScoreValue(MushroomDeath, this);
		break;
	case ScoreEvents::SpiderKilled:
		ConsoleMsg::WriteLine("SpiderDeath");
		pCmd = new CmdScoreByDistance(SpiderDistNear_Squared, SpiderDistMedium_Squared, SpiderDistFar_Squared, SpiderDeathNear, SpiderDeathMedium, SpiderDeathFar, this, BlasterFactory::GetBlaster());
		break;
	case ScoreEvents::MushroomPoisonKilled:
		ConsoleMsg::WriteLine("MushroomPoisonDeath");
		pCmd = new CmdScoreValue(MushroomPoisonDeath, this);
		break;
	case ScoreEvents::MushroomRegen:
		ConsoleMsg::WriteLine("MushroomRegen");
		pCmd = new CmdScoreValue(MushroomRegen, this);
		break;
	case ScoreEvents::CentipedeHeadKilled:
		pCmd = new CmdScoreValue(CentipedeHeadDeath, this);
		break;
	case ScoreEvents::CentipedeBodyKilled:
		pCmd = new CmdScoreValue(CentipedeBodyDeath, this);
		break;
	default:
		ConsoleMsg::WriteLine("<nothing>");
		break;
	}

	return pCmd;
}

void ScoreManager::AddScore(int val)
{
	ConsoleMsg::WriteLine("\tCurrent player score -> Add " + std::to_string(val));

	Player* p = pPlayerManager->GetCurrentPlayer(); // get current player
	p->SetScore(p->GetScore() + val); // set current player's score
	p->SetExtraLifeCounter(p->GetExtraLifeCounter() + val);
}

void ScoreManager::SendScoreCmd(CmdScore* c)
{
	QueueCmds.push(c);
}

void ScoreManager::ClearQueue()
{
	while (!QueueCmds.empty())
	{
		QueueCmds.pop();
	}
}

void ScoreManager::ProcessScores()
{
	//ConsoleMsg::WriteLine("\n\tProcessing all scores commands for this frame:");

	CmdScore* c;

	while (!QueueCmds.empty())
	{
		c = QueueCmds.front();
		c->Execute();

		QueueCmds.pop();
	}


	pHUDManager->SetPlayerScore(pPlayerManager->GetCurrentPlayer()->GetScore());

	// update highscore if player achieved new highscore
	if (pPlayerManager->GetCurrentPlayer()->GetScore() > highscore)
	{
		highscore = pPlayerManager->GetCurrentPlayer()->GetScore();
		pHUDManager->SetHighscoreTop(highscore);
	}

	// give player extra life if extra life counter reaches threshold
	if (pPlayerManager->GetCurrentPlayer()->GetExtraLifeCounter() >= GameConstants::EXTRALIFE_POINT_THRESHOLD)
	{
		pCmdExtraLifeSnd->SendToManager();
		pPlayerManager->GetCurrentPlayer()->SetLives(pPlayerManager->GetCurrentPlayer()->GetLives() + 1);
		pHUDManager->SetPlayerLives(pPlayerManager->GetCurrentPlayer()->GetLives());
		pPlayerManager->GetCurrentPlayer()->SetExtraLifeCounter(0);
	}
}

void ScoreManager::SetActive()
{
	CurrentProcessScoreMode = pProcessScoreModeActive;
}
void ScoreManager::SetInactive()
{
	CurrentProcessScoreMode = pProcessScoreModeInactive;
}

void ScoreManager::ScoreUpdate()
{
	CurrentProcessScoreMode->ScoreUpdate(this);
}

int ScoreManager::GetHighscore()
{
	return highscore;
}

ScoreManager::~ScoreManager()
{
	delete pProcessScoreModeActive;
	delete pProcessScoreModeInactive;
}
