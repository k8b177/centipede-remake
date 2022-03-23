// EnemySpawner

#ifndef _EnemySpawner
#define _EnemySpawner

#include "Game Components/TEAL/CommonElements.h"

class EnemySpawner : GameObject
{
public:
	EnemySpawner();

	virtual void Update();

	static bool canSpawnCentipede;
	static bool canSpawnScorpion;
	static bool canSpawnFlea;
	static bool canSpawnSpider;

	sf::Keyboard::Key CENTIPEDE_KEY = sf::Keyboard::Key::Num4;
	sf::Keyboard::Key SCORPION_KEY = sf::Keyboard::Key::Num1;
	sf::Keyboard::Key FLEA_KEY = sf::Keyboard::Key::Num2;

	sf::Keyboard::Key SPIDER_KEY = sf::Keyboard::Key::Num3;
};

#endif _EnemySpawner
