// MushroomFactory
// Katherine Burnett, October 2021

#include "MushroomFactory.h"
#include "Game Components/TEAL/CommonElements.h"
#include "Mushroom.h"
#include "CmdScore.h"
#include "CmdSound.h"
#include "ScoreManager.h"

#include "GameManager.h"
#include "GridManager.h"

MushroomFactory* MushroomFactory::ptrInstance = nullptr;

MushroomFactory::MushroomFactory()
	:pGridManager(nullptr), pPoisonShroomDeath(nullptr), pRegularShroomDeath(nullptr), pRegenSnd(nullptr), pRegenPoints(nullptr)
{
	
}

MushroomFactory& MushroomFactory::Instance()
{
	if (!ptrInstance)
		ptrInstance = new MushroomFactory();
	return *ptrInstance;
}

void MushroomFactory::privSetGridManager(GridManager* pGridManager)
{
	this->pGridManager = pGridManager;
}

void MushroomFactory::privSetCmdScores(CmdScore* pCmdScorePoison, CmdScore* pCmdScoreRegular, CmdScore* pCmdScoreRegen)
{
	pPoisonShroomDeath = pCmdScorePoison;
	pRegularShroomDeath = pCmdScoreRegular;
	pRegenPoints = pCmdScoreRegen;
}

void MushroomFactory::privSetCmdSound(CmdSound* pRegenSnd)
{
	this->pRegenSnd = pRegenSnd;
}

void MushroomFactory::privCreateMushroom(int row, int col)
{
	if (pGridManager->GetMushroomAt(row, col) == nullptr)
	{
		Mushroom* m = myMushroomPool.GetMushroom();

		// Declares that this object should be returned here (rather than deleted) when destroyed
		m->SetExternalManagement(RecycleMushroom);

		m->Initialize(row, col, GridInfo::GetVectPosAtColRow(col, row), pPoisonShroomDeath, pRegularShroomDeath, pRegenPoints, pRegenSnd, pGridManager);
		pGridManager->InsertMushroomIntoField(m);
	}
}

void MushroomFactory::privRecycleMushroom(GameObject* m)
{
	myMushroomPool.ReturnMushroom(static_cast<Mushroom*>(m));
}


void MushroomFactory::Terminate()
{
	delete ptrInstance->pRegenSnd;
	delete ptrInstance->pPoisonShroomDeath;
	delete ptrInstance->pRegularShroomDeath;
	delete ptrInstance->pRegenPoints;
	delete ptrInstance;
	ptrInstance = nullptr;
}
