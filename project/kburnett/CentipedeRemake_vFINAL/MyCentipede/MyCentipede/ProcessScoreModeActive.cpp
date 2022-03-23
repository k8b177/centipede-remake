#include "ProcessScoreModeActive.h"

#include "ScoreManager.h"

void ProcessScoreModeActive::ScoreUpdate(ScoreManager* pSM)
{
	pSM->ProcessScores();
}