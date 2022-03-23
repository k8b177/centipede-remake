// CentipedeHeadFactory
// Katherine Burnett, October 2021

#include "CentipedeHeadFactory.h"
#include "Game Components/TEAL/CommonElements.h"
#include "CentipedeHeadObjectPool.h"
#include "CentipedeHead.h"
#include "GameManager.h"
#include "ScoreManager.h"
#include "CmdSound.h"
#include "CmdScore.h"
#include "CentipedeSpawner.h"
#include "GridInfo.h"

CentipedeHeadFactory* CentipedeHeadFactory::ptrInstance = nullptr;

CentipedeHeadFactory::CentipedeHeadFactory()
	:ActiveHeadCount(0), pCentipedeSpawner(nullptr), pCmdScore(nullptr), pCmdSoundCrawl(nullptr), pCmdSoundKill(nullptr)
{

}

CentipedeHeadFactory& CentipedeHeadFactory::Instance()
{
	if (!ptrInstance)
		ptrInstance = new CentipedeHeadFactory();
	return *ptrInstance;
}

void CentipedeHeadFactory::privSetCentipedeSpawner(CentipedeSpawner* pCentipedeSpawner)
{
	this->pCentipedeSpawner = pCentipedeSpawner;
}

void CentipedeHeadFactory::privSetCmdScore(CmdScore* pCmdScore)
{
	this->pCmdScore = pCmdScore;
}

void CentipedeHeadFactory::privSetSoundCmds(CmdSound* pCmdSoundCrawl, CmdSound* pCmdSoundKill)
{
	this->pCmdSoundCrawl = pCmdSoundCrawl;
	this->pCmdSoundKill = pCmdSoundKill;
}

CentipedeHead* CentipedeHeadFactory::privCreateCentipedeHead(int speed, int currentFrame, int row, int col, CentipedeSegment* nextSegment, const MoveState* moveState)
{
	CentipedeHead* ch = myCentipedeHeadPool.GetCentipedeHead();

	if (ActiveCentipedeHeads.empty())
		pCmdSoundCrawl->SendToManager();

	ActiveCentipedeHeads.push_back(ch);
	ActiveHeadCount++;


	// Declares that this object should be returned here (rather than deleted) when destroyed
	ch->SetExternalManagement(RecycleCentipedeHead);

	ch->Initialize(speed, currentFrame, row, col, nextSegment, moveState, pCmdScore, pCmdSoundKill, pCentipedeSpawner);

	return ch;
}

void CentipedeHeadFactory::privRecycleCentipedeHead(GameObject* ch)
{
	CentipedeHead* centipedeHead = static_cast<CentipedeHead*>(ch);
	ActiveCentipedeHeads.erase(remove(ActiveCentipedeHeads.begin(), ActiveCentipedeHeads.end(), ch), ActiveCentipedeHeads.end());

	if (ActiveCentipedeHeads.empty())
		pCmdSoundCrawl->Stop();

	myCentipedeHeadPool.ReturnCentipedeHead(centipedeHead);
}

void CentipedeHeadFactory::privCheckCentipedeHeadCount()
{
	ActiveHeadCount--;
	ConsoleMsg::WriteLine("HeadCount = " + std::to_string(ActiveHeadCount));
	if (ActiveHeadCount <= 0)
		GameManager::EndOfWaveCallback();
}

void CentipedeHeadFactory::privFreezeAllCentipedeHeads()
{
	pCmdSoundCrawl->Stop();
	for (CentipedeHead* ch : Instance().GetActiveCentipedeHeads())
	{
		ch->Freeze();
	}
}
std::vector<CentipedeHead*> CentipedeHeadFactory::privGetActiveCentipedeHeads()
{
	return ActiveCentipedeHeads;
}

void CentipedeHeadFactory::privDestroyAllActiveCentipedeHeads()
{
	for (CentipedeHead* ch : ActiveCentipedeHeads)
	{
		ch->MarkForDestroy();
	}

	ActiveCentipedeHeads.clear();
	ActiveHeadCount = 0;
}

void CentipedeHeadFactory::Terminate()
{
	delete ptrInstance->pCmdSoundKill;
	delete ptrInstance->pCmdSoundCrawl;
	delete ptrInstance->pCmdScore;
	delete ptrInstance;
	ptrInstance = nullptr;
}
