// MushroomField
// Katherine Burnett, September 2021

#ifndef _MushroomField
#define _MushroomField

#include "Game Components/TEAL/CommonElements.h"
#include "Mushroom.h"
#include "GameConstants.h"
#include "FleaSpawner.h"
#include "GameManager.h"
#include "FieldManager.h"

#include "ObstacleEnum.h"

class Mushroom;
class FleaSpawner;
class GameManager;

class Player;

class MushroomField
{
public:
	// Big Four
	MushroomField();
	MushroomField(const MushroomField&) = default;
	MushroomField& operator= (const MushroomField&) = default;
	~MushroomField();


	static MushroomField* CurrentMushroomField;

	// MushroomField methods (specific to each mushroomfield)
	void Fill();
	static bool DropMushroomCheck();
	Mushroom* GetMushroomAt(int col, int row);
	void PutMushroomInField(Mushroom* m);
	static int Coordinate2DTo1D(int col, int row);
	void RemoveMushroomFromField(Mushroom* m);
	int GetTotalMushroomCount();
	int GetPlayerAreaMushroomCount();
	void Destroy();
	static Obstacle Inspect(int row, int col);
	void SetTotalMushroomCount(int newCount);
	void SetPlayerAreaMushroomCount(int newCount);


	static MushroomField* CreateNewMushroomField();
	// static void InitializePlayerMushroomFieldMarker(Player* player);
	// static void LoadPlayerMushroomField();
	

	static void SetField(MushroomField* newMushroomField);



	// GridManager methods (general stuff about the grid)
	static int GetRandomColumn();
	static int GetRandomRow();
	static int GetRandomRightOrLeft();
	static sf::Vector2f GetVectPosAtColRow(int col, int row);
	static const int GetFramesToMoveOneCell(int speed);
	static bool MushroomCheckAt(int col, int row, MushroomField* mushroomField);
	static bool InPlayerArea(int col, int row);

	static const int BOTTOM_ROW = 0;
	static const int RIGHT_COLUMN = GameConstants::COLUMNS - 1;
	static const int LEFT_COLUMN = 0;
	static const int TOP_ROW = GameConstants::ROWS - 1;
	static const int TOP_PLAYER_ROW = GameConstants::ROWS_IN_PLAYER_AREA - 1;
	static const int CELLSIZE = GameConstants::CELLSIZE;

private:
	Mushroom* MushroomArray[GameConstants::COLUMNS * GameConstants::ROWS];
	int totalMushroomCount;
	int playerAreaMushroomCount;

};

#endif _MushroomField


