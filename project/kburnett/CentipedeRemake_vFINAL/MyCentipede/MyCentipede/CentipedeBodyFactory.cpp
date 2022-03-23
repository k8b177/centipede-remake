// CentipedeBodyFactory
// Katherine Burnett, October 2021

#include "CentipedeBodyFactory.h"
#include "Game Components/TEAL/CommonElements.h"
#include "CentipedeBodyObjectPool.h"
#include "CentipedeBody.h"
#include "ScoreManager.h"
#include "CmdScore.h"

CentipedeBodyFactory* CentipedeBodyFactory::ptrInstance = nullptr;

CentipedeBodyFactory::CentipedeBodyFactory()
	:pCmdSoundKill(nullptr), pCmdScore(nullptr), pCentipedeSpawner(nullptr)
{
	
}

CentipedeBodyFactory& CentipedeBodyFactory::Instance()
{
	if (!ptrInstance)
		ptrInstance = new CentipedeBodyFactory();
	return *ptrInstance;
}

void CentipedeBodyFactory::privSetCentipedeSpawner(CentipedeSpawner* pCentipedeSpawner)
{
	this->pCentipedeSpawner = pCentipedeSpawner;
}

void CentipedeBodyFactory::privSetCmdScore(CmdScore* pCmdScore)
{
	this->pCmdScore = pCmdScore;
}

void CentipedeBodyFactory::privSetSoundCmds(CmdSound* pCmdSoundKill)
{
	this->pCmdSoundKill = pCmdSoundKill;
}

CentipedeBody* CentipedeBodyFactory::privCreateCentipedeBody(int speed, int currentFrame, int row, int col, const MoveState* moveState)
{
	CentipedeBody* cb = myCentipedeBodyPool.GetCentipedeBody();

	ActiveCentipedeBodies.push_back(cb);

	// Declares that this object should be returned here (rather than deleted) when destroyed
	cb->SetExternalManagement(RecycleCentipedeBody);

	cb->Initialize(speed, currentFrame, row, col, moveState, pCmdScore, pCmdSoundKill, pCentipedeSpawner);

	return cb;
}

void CentipedeBodyFactory::privRecycleCentipedeBody(GameObject* cb)
{
	CentipedeBody* centipedeBody = static_cast<CentipedeBody*>(cb);
	ActiveCentipedeBodies.erase(remove(ActiveCentipedeBodies.begin(), ActiveCentipedeBodies.end(), cb), ActiveCentipedeBodies.end());
	myCentipedeBodyPool.ReturnCentipedeBody(centipedeBody);
}

void CentipedeBodyFactory::privFreezeAllCentipedeBodies()
{
	for (CentipedeBody* cb : Instance().GetActiveCentipedeBodies())
	{
		cb->Freeze();
	}
}
std::vector<CentipedeBody*> CentipedeBodyFactory::privGetActiveCentipedeBodies()
{
	return ActiveCentipedeBodies;
}

void CentipedeBodyFactory::privDestroyAllActiveCentipedeBodies()
{
	for (CentipedeBody* cb : Instance().GetActiveCentipedeBodies())
	{
		cb->MarkForDestroy();
	}
}

void CentipedeBodyFactory::Terminate()
{
	delete ptrInstance->pCmdScore;
	delete ptrInstance;
	ptrInstance = nullptr;
}
