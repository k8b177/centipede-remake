// GameConstants
// Katherine Burnett, September 2021

#ifndef _GameConstants
#define _GameConstants

#include "Game Components/TEAL/CommonElements.h"


class GameConstants
{
public:
	// player info
	static const int PLAYER_COUNT = 1;
	static const int PLAYER_COUNT_MAX;
	static const int PLAYER_LIVES_MAX = 3;

	// grid info
	static const int SPRITE_SCALE = 1; // how much to scale the 16x16 sprites
	static const int CELLSIZE = SPRITE_SCALE * 16; // for us, should remain 32x32
	static const int HALF_CELLSIZE = CELLSIZE / 2; // computing once since it is used a lot
	static const int ROWS = 32;
	static const int COLUMNS = 30;
	static const int ROWS_IN_PLAYER_AREA = 5;

	// window coordinate info
	static const int COLUMN_ORIGIN = GameConstants::HALF_CELLSIZE; // y coordinate of first row
	static const int ROW_ORIGIN = GameConstants::HALF_CELLSIZE + GameConstants::CELLSIZE * (GameConstants::ROWS - 1); // x coordiate of first row
	static float WINDOWSIZE_X;
	static float WINDOWSIZE_Y;

	// mushroom info
	static const int PROBABILITY_OF_MUSHROOM = 4; //as a percent
	static const int MUSHROOM_DEAD_HEALTH = 4;

	// blaster info
	static const int BLASTER_SPEED = 4;

	// bullet info
	static const int BULLET_SPEED = 500;

	// animation info
	static const int FPS_ANIMATION = 15;
	static float CENTIPEDETURN_ANGLEINCREMENT;

	// scorpion info
	static const int MIN_SCORPION_SPAWN_ROW = ROWS_IN_PLAYER_AREA;
	static const int MAX_SCORPION_SPAWN_ROW = ROWS - 1;
	static const int MIN_SCORPION_SPEED = 200;
	static const int MAX_SCORPION_SPEED = 700;
	static const int PROBABILITY_OF_POISON = 20; //as a percent

	// spider info
	static const int MIN_SPIDER_SPAWN_ROW = 0;
	static const int MAX_SPIDER_SPAWN_ROW = ROWS / 3;
	static const int MIN_SPIDER_SPEED = 100;
	static const int MAX_SPIDER_SPEED = 260;
	static const int PROBABILITY_OF_EATING = 20; //as a percent
	static const int MIN_SPIDER_CHANGEDIRECTION_TIMEINTERVAL = 1; // x4
	static const int MAX_SPIDER_CHANGEDIRECTION_TIMEINTERVAL = 8; // x4

	// flea info
	static const int FLEA_SPEED = 4;  // in pixels / frame
	static const int MUSHROOM_COUNT_TO_SPAWN_FLEA = 5;

	// centipede info
	static float TIME_BEFORE_HEADS_IN_PLAYER_AREA_SPAWN;
	static float TIME_BETWEEN_CENTIPEDE_HEAD_SPAWNING;

	// wave info
	static const int WAVE_TOTAL_COUNT = 4;

	// keys assignments
	static const sf::Keyboard::Key START_1PLAYERMODE_KEY = sf::Keyboard::Key::Num1;
	static const sf::Keyboard::Key START_2PLAYERMODE_KEY = sf::Keyboard::Key::Num2;

	// HUD info
	static const int NUM_HIGHSCORE_ENTRIES = 8;
	static const int MAX_SCORE_SPACES = 6;

	// sound info
	static float VOLUME;

	// score info
	static const int EXTRALIFE_POINT_THRESHOLD = 300;
};

#endif _GameConstants