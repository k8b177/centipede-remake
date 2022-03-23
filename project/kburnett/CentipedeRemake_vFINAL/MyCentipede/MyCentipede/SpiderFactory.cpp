// SpiderFactory
// Katherine Burnett, October 2021

#include "SpiderFactory.h"
#include "Game Components/TEAL/CommonElements.h"
#include "SpiderObjectPool.h"
#include "Spider.h"
#include "CmdSound.h"
#include "CmdScore.h"
#include "ScoreManager.h"

SpiderFactory* SpiderFactory::ptrInstance = nullptr;

SpiderFactory::SpiderFactory()
	:pCmdScore(nullptr), pCmdSoundCrawl(nullptr), pCmdSoundKill(nullptr), pGridManager(nullptr), pSpiderSpawner(nullptr)
{
	//pCmdScore = ScoreManager::GetScoreCommand(ScoreEvents::SpiderKilled);
}

SpiderFactory& SpiderFactory::Instance()
{
	if (!ptrInstance)
		ptrInstance = new SpiderFactory();
	return *ptrInstance;
}

void SpiderFactory::privCreateSpider(sf::Vector2f pos, int speed, int row, int col, int direction)
{
	Spider* s = mySpiderObjectPool.GetSpider();

	if (ActiveSpiders.empty())
		pCmdSoundCrawl->SendToManager();

	ActiveSpiders.push_back(s);

	// Declares that this object should be returned here (rather than deleted) when destroyed
	s->SetExternalManagement(RecycleSpider);

	s->Initialize(pos, speed, row, col, direction, pCmdScore, pCmdSoundKill, pGridManager, pSpiderSpawner);
}

void SpiderFactory::privRecycleSpider(GameObject* s)
{
	Spider* spider = static_cast<Spider*>(s);
	ActiveSpiders.erase(remove(ActiveSpiders.begin(), ActiveSpiders.end(), s), ActiveSpiders.end());

	if (ActiveSpiders.empty())
		pCmdSoundCrawl->Stop();

	mySpiderObjectPool.ReturnSpider(spider);
}

void SpiderFactory::privSetSpiderSpawner(SpiderSpawner* pSpiderSpawner)
{
	this->pSpiderSpawner = pSpiderSpawner;
}

void SpiderFactory::privSetGridManager(GridManager* pGridManager)
{
	this->pGridManager = pGridManager;
}

void SpiderFactory::privSetCmdScore(CmdScore* pCmdScore)
{
	this->pCmdScore = pCmdScore;
}

void SpiderFactory::privSetSoundCmds(CmdSound* pCmdSoundCrawl, CmdSound* pCmdSoundKill)
{
	this->pCmdSoundCrawl = pCmdSoundCrawl;
	this->pCmdSoundKill = pCmdSoundKill;
}

std::vector<Spider*> SpiderFactory::privGetActiveSpiders()
{
	return ActiveSpiders;
}

void SpiderFactory::privFreezeAllSpiders()
{
	pCmdSoundCrawl->Stop();
	for (Spider* s : Instance().GetActiveSpiders())
	{
		s->Freeze();
	}
}

void SpiderFactory::privDestroyAllActiveSpiders()
{
	for (Spider* s : Instance().GetActiveSpiders())
	{
		s->MarkForDestroy();
	}
}

void SpiderFactory::Terminate()
{
	delete ptrInstance->pCmdScore;
	delete ptrInstance->pCmdSoundCrawl;
	delete ptrInstance;
	ptrInstance = nullptr;
}
