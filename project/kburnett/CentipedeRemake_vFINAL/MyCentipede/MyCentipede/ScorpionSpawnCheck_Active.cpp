#include "ScorpionSpawnCheck_Active.h"


#include "ScorpionSpawner.h"

ScorpionSpawnCheck_Active::ScorpionSpawnCheck_Active(ScorpionSpawner* pScorpionSpawner)
	:pScorpionSpawner(pScorpionSpawner)
{

}

void ScorpionSpawnCheck_Active::StartScorpionSpawnTimer()
{
	pScorpionSpawner->StartTimer();
}