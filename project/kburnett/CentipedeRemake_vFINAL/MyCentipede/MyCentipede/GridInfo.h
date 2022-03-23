// GridInfo Header

#include "GameConstants.h"

// grid info

#ifndef _GridInfo
#define _GridInfo


struct GridInfo 
{
	static const int SPRITE_SCALE = GameConstants::SPRITE_SCALE; // how much to scale the 16x16 sprites
	static const int CELLSIZE = GameConstants::CELLSIZE; // should remain 16x16
	static const int HALF_CELLSIZE = CELLSIZE / 2; // computing once since it is used a lot
	static const int ROWS = GameConstants::ROWS;
	static const int COLUMNS = GameConstants::COLUMNS;
	static const int GRID_SIZE = ROWS * COLUMNS;
	static const int COLUMN_ORIGIN = HALF_CELLSIZE; // y coordinate of first row
	static const int ROW_ORIGIN = HALF_CELLSIZE + CELLSIZE * (ROWS); // x coordiate of first row
	static const int BOTTOM_ROW = 0;
	static const int RIGHT_COLUMN = GameConstants::COLUMNS - 1;
	static const int LEFT_COLUMN = 0;
	static const int TOP_ROW = GameConstants::ROWS - 1;
	static const int ROWS_IN_PLAYER_AREA = GameConstants::ROWS_IN_PLAYER_AREA;
	static const int TOP_PLAYER_ROW = ROWS_IN_PLAYER_AREA - 1;
	
	// Methods
	static int GetRandomColumn(); // returns random column in the grid
	static int GetRandomRow(); // returns random row in the grid
	static int GetRandomScorpionSpawnRow();
	static int GetRandomRowInPlayerArea();
	static int GetRandomRightOrLeft(); // returns 1 (right) or -1 (left), 50% chance of each
	static sf::Vector2f GetVectPosAtColRow(int col, int row); // returns the corresponding Vector position given a column and row
	static const int GetFramesToMoveOneCell(int speed); // returns how many frames it will take to move 1 cell given a speed
	static bool InPlayerArea(int col, int row); // returns a bool - true if (col, row) is in player area, flase if (col, row) is not in player area
	static int Coordinate2DTo1D(int col, int row);// converts (col, row) coordinate to corresponding index of 1D array
};

#endif // !_GridInfo

