// FleaFactory
// Katherine Burnett, October 2021

#include "FleaFactory.h"
#include "Game Components/TEAL/CommonElements.h"
#include "FleaObjectPool.h"
#include "Flea.h"
#include "ScoreManager.h"

#include "CmdSound.h"
#include "CmdScore.h"

FleaFactory* FleaFactory::ptrInstance = nullptr;

FleaFactory::FleaFactory()
	:CurrentMushroomSpawnProbability(0.0f), pCmdScore(nullptr), pCmdSoundCrawl(nullptr), pCmdSoundKill(nullptr), pFleaSpawner(nullptr), pGridManager(nullptr)
{
	
}

FleaFactory& FleaFactory::Instance()
{
	if (!ptrInstance)
		ptrInstance = new FleaFactory();
	return *ptrInstance;
}

void FleaFactory::privCreateFlea(sf::Vector2f pos, int col)
{
	if (!ActiveFleas.empty()) return;

	Flea* f = myFleaPool.GetFlea();
	pCmdSoundCrawl->SendToManager();

	ActiveFleas.push_back(f);

	// Declares that this object should be returned here (rather than deleted) when destroyed
	f->SetExternalManagement(RecycleFlea);

	f->Initialize(pos, col, CurrentMushroomSpawnProbability, pCmdScore, pCmdSoundKill, pGridManager, pFleaSpawner);
}

void FleaFactory::privRecycleFlea(GameObject* f)
{
	Flea* flea = static_cast<Flea*>(f);
	ActiveFleas.erase(remove(ActiveFleas.begin(), ActiveFleas.end(), f), ActiveFleas.end());
	myFleaPool.ReturnFlea(flea);
}

void FleaFactory::privSetFleaSpawner(FleaSpawner* pFleaSpawner)
{
	this->pFleaSpawner = pFleaSpawner;
}

void FleaFactory::privSetGridManager(GridManager* pGridManager)
{
	this->pGridManager = pGridManager;
}

void FleaFactory::privSetCmdScore(CmdScore* pCmdScore)
{
	this->pCmdScore = pCmdScore;
}

void FleaFactory::privSetSoundCmds(CmdSound* pCmdSoundCrawl, CmdSound* pCmdSoundKill)
{
	this->pCmdSoundCrawl = pCmdSoundCrawl;
	this->pCmdSoundKill = pCmdSoundKill;
}

void FleaFactory::privFreezeAllFleas()
{
	pCmdSoundCrawl->Stop();
	for (Flea* f : Instance().GetActiveFleas())
	{
		f->Freeze();
	}
}
std::vector<Flea*> FleaFactory::privGetActiveFleas()
{
	return ActiveFleas;
}

void FleaFactory::privDestroyAllActiveFleas()
{
	for (Flea* f : ActiveFleas)
	{
		f->MarkForDestroy();
	}
}

void FleaFactory::Terminate()
{
	delete ptrInstance->pCmdScore;
	delete ptrInstance->pCmdSoundCrawl;
	delete ptrInstance;
	ptrInstance = nullptr;
}
