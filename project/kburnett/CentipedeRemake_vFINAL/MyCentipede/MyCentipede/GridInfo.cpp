// GridInfo

#include "GridInfo.h"

int GridInfo::GetRandomColumn() // returns column in the grid
{
	return rand() % (GridInfo::COLUMNS - 1);
}

int GridInfo::GetRandomRow() // returns random row in the grid
{
	return rand() % (GridInfo::ROWS - 1);
}

int GridInfo::GetRandomScorpionSpawnRow()
{
	return rand() % (GameConstants::MAX_SCORPION_SPAWN_ROW - GameConstants::MIN_SCORPION_SPAWN_ROW) + GameConstants::MIN_SCORPION_SPAWN_ROW + 1;
}

int GridInfo::GetRandomRowInPlayerArea()
{
	return rand() % (GridInfo::TOP_PLAYER_ROW);
}

int GridInfo::GetRandomRightOrLeft()
{
	if (rand() % 2 == 0) // right
		return 1;
	else // left
		return -1;
}

sf::Vector2f GridInfo::GetVectPosAtColRow(int col, int row) // returns the corresponding Vector position given a column and row
{
	return sf::Vector2f((float)GridInfo::COLUMN_ORIGIN + GridInfo::CELLSIZE * col, (float)GridInfo::ROW_ORIGIN - GridInfo::CELLSIZE * row);
}

const int GridInfo::GetFramesToMoveOneCell(int speed) // returns how many frames it will take to move 1 cell given a speed
{
	return GridInfo::CELLSIZE / speed;
}

bool GridInfo::InPlayerArea(int col, int row) // returns a bool - true if (col, row) is in player area, flase if (col, row) is not in player area
{
	return (row <= GridInfo::ROWS_IN_PLAYER_AREA);
}

int GridInfo::Coordinate2DTo1D(int col, int row)
{
	return col * GridInfo::ROWS + row;
}
