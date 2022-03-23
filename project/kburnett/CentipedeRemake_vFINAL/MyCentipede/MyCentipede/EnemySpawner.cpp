#include "EnemySpawner.h"

#include "CentipedeSpawner.h"
#include "ScorpionSpawner.h"
#include "FleaSpawner.h"
#include "Spider.h"

bool EnemySpawner::canSpawnCentipede = true;
bool EnemySpawner::canSpawnScorpion = true;
bool EnemySpawner::canSpawnFlea = true;
bool EnemySpawner::canSpawnSpider = true;

EnemySpawner::EnemySpawner()
{

}

void EnemySpawner::Update()
{
	// Centipede: spawning when key pressed
	if (sf::Keyboard::isKeyPressed(CENTIPEDE_KEY) && canSpawnCentipede)
		CentipedeSpawner::SpawnNewCentipedeAtTop(20, 1);
	else if (!sf::Keyboard::isKeyPressed(CENTIPEDE_KEY) && !canSpawnCentipede) // resetting canSpawn when key released
		canSpawnCentipede = true;

	// Scorpion: spawning when key pressed
	/*
	if (sf::Keyboard::isKeyPressed(SCORPION_KEY) && canSpawnScorpion)
		ScorpionSpawner::SpawnNewScorpion(1);
	else if (!sf::Keyboard::isKeyPressed(SCORPION_KEY) && !canSpawnScorpion) // resetting canSpawn when key released)
		canSpawnScorpion = true;
	*/

	// Flea: spawning when key pressed
	/*
	if (sf::Keyboard::isKeyPressed(FLEA_KEY) && canSpawnFlea)
		FleaSpawner::CheckSpawnNewFlea();
	else if (!sf::Keyboard::isKeyPressed(FLEA_KEY) && !canSpawnFlea) // resetting canSpawn when key released)
		canSpawnFlea = true;
		*/

	// Flea: spawning when key pressed
	/*if (sf::Keyboard::isKeyPressed(SPIDER_KEY) && canSpawnSpider)
		(new Spider())->Initialize(MushroomField::GetVectPosAtColRow(5, 5), 2, 5, 5, 1);
	else if (!sf::Keyboard::isKeyPressed(SPIDER_KEY) && !canSpawnSpider) // resetting canSpawn when key released)
		canSpawnSpider = true;*/
}