#include "P1HUDMode.h"

#include "HUDManager.h"

void P1HUDMode::SetPlayerScore(HUDManager* pHM, int score)
{
	pHM->SetP1Score(score);
}

void P1HUDMode::SetPlayerLife(HUDManager* pHM, int lives)
{
	pHM->SetP1Lives(lives);
}