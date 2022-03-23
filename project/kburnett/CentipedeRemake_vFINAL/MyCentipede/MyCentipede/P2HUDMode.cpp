#include "P2HUDMode.h"

#include "HUDManager.h"

void P2HUDMode::SetPlayerScore(HUDManager* pHM, int score)
{
	pHM->SetP2Score(score);
}

void P2HUDMode::SetPlayerLife(HUDManager* pHM, int lives)
{
	pHM->SetP2Lives(lives);
}