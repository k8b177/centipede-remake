// ScorpionFactory
// Katherine Burnett, October 2021

#include "ScorpionFactory.h"
#include "Game Components/TEAL/CommonElements.h"
#include "ScorpionObjectPool.h"
#include "Scorpion.h"
#include "ScoreManager.h"
#include "ScorpionSpawner.h"
#include "CmdSound.h"
#include "CmdScore.h"

ScorpionFactory* ScorpionFactory::ptrInstance = nullptr;

ScorpionFactory::ScorpionFactory()
	:pCmdScore(nullptr), pCmdSoundCrawl(nullptr), pCmdSoundKill(nullptr), pGridManager(nullptr), pScorpionSpawner(nullptr)
{
	
}

ScorpionFactory& ScorpionFactory::Instance()
{
	if (!ptrInstance)
		ptrInstance = new ScorpionFactory();
	return *ptrInstance;
}

void ScorpionFactory::privCreateScorpion(sf::Vector2f pos, int speed, int row, int col, int direction)
{
	Scorpion* s = myScorpionPool.GetScorpion();

	if (ActiveScorpions.empty())
		pCmdSoundCrawl->SendToManager();

	ActiveScorpions.push_back(s);

	// Declares that this object should be returned here (rather than deleted) when destroyed
	s->SetExternalManagement(RecycleScorpion);

	s->Initialize(pos, speed, row, col, direction, pCmdScore, pCmdSoundKill, pGridManager, pScorpionSpawner);
}

void ScorpionFactory::privRecycleScorpion(GameObject* s)
{
	Scorpion* scorpion = static_cast<Scorpion*>(s);
	ActiveScorpions.erase(remove(ActiveScorpions.begin(), ActiveScorpions.end(), s), ActiveScorpions.end());

	if (ActiveScorpions.empty())
		pCmdSoundCrawl->Stop();

	myScorpionPool.ReturnScorpion(scorpion);
}

void ScorpionFactory::privSetGridManager(GridManager* pGridManager)
{
	this->pGridManager = pGridManager;
}

void ScorpionFactory::privSetScorpionSpawner(ScorpionSpawner* pScorpionSpawner)
{
	this->pScorpionSpawner = pScorpionSpawner;
}

void ScorpionFactory::privSetCmdScore(CmdScore* pCmdScore)
{
	this->pCmdScore = pCmdScore;
}

void ScorpionFactory::privSetSoundCmds(CmdSound* pCmdSoundCrawl, CmdSound* pCmdSoundKill)
{
	this->pCmdSoundCrawl = pCmdSoundCrawl;
	this->pCmdSoundKill = pCmdSoundKill;
}

std::vector<Scorpion*> ScorpionFactory::privGetActiveScorpions()
{
	return ActiveScorpions;
}

void ScorpionFactory::privFreezeAllScorpions()
{
	pCmdSoundCrawl->Stop();
	for (Scorpion* s : Instance().GetActiveScorpions())
	{
		s->Freeze();
	}
}

void ScorpionFactory::privDestroyAllActiveScorpions()
{
	for (Scorpion* s : Instance().GetActiveScorpions())
	{
		s->MarkForDestroy();
	}
}

void ScorpionFactory::Terminate()
{
	delete ptrInstance->pCmdScore;
	delete ptrInstance->pCmdSoundCrawl;
	delete ptrInstance;
	ptrInstance = nullptr;
}
