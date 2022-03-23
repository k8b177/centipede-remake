#include "GridManager.h"

#include "Player.h"
#include "MushroomFieldData.h"
#include "MushroomFactory.h"
#include "GridInfo.h"
#include "Mushroom.h"
#include "GameManager.h"
#include "FleaSpawner.h"
#include "TextBlock.h"
#include "PlayerManager.h"

GridManager::GridManager():PlayerAreaMushroomCount(0), TotalMushroomCount(0), pFleaSpawner(nullptr)
{
	// filling CurrentMushroomField with nullptrs to start
	for (int i = 0; i < GridInfo::GRID_SIZE; i++)
		CurrentMushroomField[i] = nullptr;
	
	// filling TextBlockField with nullptrs to start
	for (int i = 0; i < GridInfo::GRID_SIZE; i++)
		TextBlockField[i] = nullptr;

	pPlayerManager = GameManager::PlayerManagerAccessor();
}

void GridManager::FillCurrentMushroomFieldFromPlayerData(Player* currentPlayer)
{
	MushroomFieldData* playerMushroomFieldData = currentPlayer->GetMushroomFieldData();

	// placing mushrooms in grid based on player's mushroom field data
	for (int col = 0; col < GridInfo::COLUMNS; col++)
	{
		for (int row = 1; row < GridInfo::ROWS; row++)
		{
			int index = GridInfo::Coordinate2DTo1D(col, row);

			// destroy old mushrooms
			Mushroom* m = CurrentMushroomField[index];
			if (m != nullptr)
				m->MarkForDestroy();

			// fill based on player data
			if (playerMushroomFieldData->GetMushroomDataAt(index).filled)
				MushroomFactory::CreateMushroom(row, col); //CreateMushroom method updates CurrentMushroomField[index]
			else
				CurrentMushroomField[index] = nullptr;
		}
	}
}

Mushroom* GridManager::GetMushroomAt(int row, int col)
{
	return CurrentMushroomField[GridInfo::Coordinate2DTo1D(col, row)];
}

TextBlock* GridManager::GetTextBlockAt(int row, int col)
{
	return TextBlockField[GridInfo::Coordinate2DTo1D(col, row)];
}

void GridManager::InsertMushroomIntoField(Mushroom* m)
{
	int row = m->row;
	int col = m->col;

	TotalMushroomCount++;
	if (GridInfo::InPlayerArea(col, row)) PlayerAreaMushroomCount++;

	pPlayerManager->GetCurrentPlayer()->SetMushroomDataAtRowCol(row, col, true);
	CurrentMushroomField[GridInfo::Coordinate2DTo1D(col, row)] = m;
}

void GridManager::InsertTextBlockIntoField(TextBlock* t)
{
	int row = t->row;
	int col = t->col;

	TextBlockField[GridInfo::Coordinate2DTo1D(col, row)] = t;
}

void GridManager::RemoveMushroomFromField(Mushroom* m)
{
	int row = m->row;
	int col = m->col;

	pPlayerManager->GetCurrentPlayer()->SetMushroomDataAtRowCol(row, col, false);

	TotalMushroomCount--;
	if (GridInfo::InPlayerArea(col, row)) {
		PlayerAreaMushroomCount--;
		pFleaSpawner->CheckSpawnNewFlea(PlayerAreaMushroomCount);
	}

	CurrentMushroomField[GridInfo::Coordinate2DTo1D(col, row)] = nullptr;
}

void GridManager::RemoveTextBlockFromField(TextBlock* t)
{
	int row = t->row;
	int col = t->col;

	TextBlockField[GridInfo::Coordinate2DTo1D(col, row)] = nullptr;
}

Obstacle GridManager::Inspect(int row, int col) // static
{
	int ans;
	//0=clear, 1=block, 2=Poison

	if (col < GridInfo::LEFT_COLUMN || col > GridInfo::RIGHT_COLUMN)
		ans = 1;
	else
	{
		Mushroom* mush = GameManager::GridManagerAccessor()->GetMushroomAt(row, col);
		TextBlock* t = GameManager::GridManagerAccessor()->GetTextBlockAt(row, col);
		if (mush)
		{
			if (mush->poisoned)
				ans = 2;
			else
				ans = 1;
		}
		else if (t)
			ans = 1;
		else
			ans = 0;
	}

	return (Obstacle)ans;
}

int GridManager::GetPlayerAreaMushroomCount()
{
	return PlayerAreaMushroomCount;
}

void GridManager::SetFleaSpawner(FleaSpawner* pFleaSpawner)
{
	this->pFleaSpawner = pFleaSpawner;
}