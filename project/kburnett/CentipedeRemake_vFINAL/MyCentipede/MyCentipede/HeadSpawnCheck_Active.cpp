#include "HeadSpawnCheck_Active.h"

#include "CentipedeSpawner.h"
#include "GameConstants.h"

HeadSpawnCheck_Active::HeadSpawnCheck_Active(CentipedeSpawner* pCentipedeSpawner)
	:pCentipedeSpawner(pCentipedeSpawner)
{

}


void HeadSpawnCheck_Active::CheckToSpawnHead(int CurrentCount_HeadsInPlayerArea, int CentipedeSoloHeadInPlayerAreaCount)
{
	// Only Spawn if number of centipedeHeads in player area is below specified threshold
	if (CurrentCount_HeadsInPlayerArea < CentipedeSoloHeadInPlayerAreaCount)
	{
		if (!pCentipedeSpawner->AlarmActive(0))
			pCentipedeSpawner->SetAlarm(0, GameConstants::TIME_BETWEEN_CENTIPEDE_HEAD_SPAWNING);
	}
}