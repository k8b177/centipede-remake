#include "MushroomFieldData.h"

#include "GridInfo.h"

void MushroomFieldData::InitializeMushroomFieldData()
{
	for (int col = 0; col < GridInfo::COLUMNS; col++)
	{
		for (int row = 1; row < GridInfo::ROWS; row++)
		{
			int index = GridInfo::Coordinate2DTo1D(col, row);
			if (DropMushroomCheck())
				myMushroomData[index].filled = true;
			else
				myMushroomData[index].filled = false;
		}
	}
}

bool MushroomFieldData::DropMushroomCheck()
{
	return rand() % 100 < (GameConstants::PROBABILITY_OF_MUSHROOM);
}

MushroomData MushroomFieldData::GetMushroomDataAt(int i)
{
	return myMushroomData[i];
}

void MushroomFieldData::SetMushroomDataAtRowCol(int row, int col, bool filled)
{
	myMushroomData[GridInfo::Coordinate2DTo1D(col, row)].filled = filled;
}