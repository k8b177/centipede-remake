// MushroomField
// Katherine Burnett, September 2021

#include "MushroomField.h"
#include "GameManager.h"
#include "MushroomFactory.h"
#include "FleaSpawner.h"

#include "Player.h"
#include "PlayerManager.h"


MushroomField* MushroomField::CurrentMushroomField = nullptr;

MushroomField::MushroomField():totalMushroomCount(0), playerAreaMushroomCount(0)
{
	for (int i = 0; i < GameConstants::COLUMNS * GameConstants::ROWS; i++)
	{
		MushroomArray[i] = nullptr;
	}
}

void MushroomField::Fill()
{
	//placing mushrooms randomly in all rows (except bottom one)
	for (int col = 0; col < GameConstants::COLUMNS; col++)
	{
		for (int row = 1; row < GameConstants::ROWS; row++)
		{
			if (DropMushroomCheck())
			{
				//MushroomFactory::CreateMushroom(row, col);
			}
			else
				MushroomArray[Coordinate2DTo1D(col, row)] = nullptr;
		}
	}
	// ConsoleMsg::WriteLine("totalMushroomCount: " + std::to_string(totalMushroomCount));
	// ConsoleMsg::WriteLine("playerAreaMushroomCount: " + std::to_string(playerAreaMushroomCount));

	// putting nullptrs in the bottom row of the mushroom field
	for (int col = 0; col < GameConstants::COLUMNS; col++)
		MushroomArray[Coordinate2DTo1D(col, 0)] = nullptr;

	//this->fleaSpawner = gameManager->fleaSpawner;
}

/*void MushroomField::InitializePlayerMushroomFieldMarker(Player* player)
{
	//placing mushrooms randomly in all rows (except bottom one)
	int index;
	for (int col = 0; col < GameConstants::COLUMNS; col++)
	{
		for (int row = 1; row < GameConstants::ROWS; row++)
		{
			index = MushroomField::Coordinate2DTo1D(col, row);
			if (DropMushroomCheck())
			{
				//MushroomFactory::CreateMushroom(row, col);
				player->SetMushroomFieldMarkerAt(index, true);

			}
			else
				player->SetMushroomFieldMarkerAt(index, false);
		}
	}

	// putting no mushrooms in the bottom row of the mushroom field
	for (int col = 0; col < GameConstants::COLUMNS; col++)
		player->SetMushroomFieldMarkerAt(index, false);
}

void MushroomField::LoadPlayerMushroomField()
{
	// Looping through CurrentPlayer's MushroomFieldMarker array and creating an Mushroom if marked true
	int index;
	for (int col = 0; col < GameConstants::COLUMNS; col++)
	{
		for (int row = 0; row < GameConstants::ROWS; row++)
		{
			index = MushroomField::Coordinate2DTo1D(col, row);
			if (PlayerManager::GetCurrentPlayer()->GetMushroomFieldMarkerAt(index))
				MushroomFactory::CreateMushroom(row, col);
			else
				MushroomField::CurrentMushroomField->MushroomArray[index] = nullptr;
		}
	}
}
*/


void MushroomField::PutMushroomInField(Mushroom* m)
{
	//ConsoleMsg::WriteLine("playerAreaMushroomCount: " + std::to_string(playerAreaMushroomCount));

	int row = m->row;
	int col = m->col;

	totalMushroomCount++;
	if (InPlayerArea(col, row)) playerAreaMushroomCount++;
	MushroomArray[Coordinate2DTo1D(col, row)] = m;
}


bool MushroomField::DropMushroomCheck()
{
	return rand() % 100 < (GameConstants::PROBABILITY_OF_MUSHROOM);
}

sf::Vector2f MushroomField::GetVectPosAtColRow(int col, int row)
{
	return sf::Vector2f((float)GameConstants::COLUMN_ORIGIN + GameConstants::CELLSIZE * col, (float)GameConstants::ROW_ORIGIN - GameConstants::CELLSIZE * row);
}

Mushroom* MushroomField::GetMushroomAt(int col, int row)
{
	return MushroomArray[Coordinate2DTo1D(col, row)];
}

int MushroomField::Coordinate2DTo1D(int col, int row)
{
	return col * GameConstants::ROWS + row;
}

void MushroomField::RemoveMushroomFromField(Mushroom* m)
{
	int row = m->row;
	int col = m->col;

	totalMushroomCount--;
	if (InPlayerArea(col, row)) {
		playerAreaMushroomCount--;
		//FleaSpawner::CheckSpawnNewFlea();
	}

	MushroomArray[Coordinate2DTo1D(col, row)] = nullptr;


	ConsoleMsg::WriteLine("playerAreaMushroomCount: " + std::to_string(playerAreaMushroomCount));
}

bool MushroomField::InPlayerArea(int col, int row)
{
	return (row <= GameConstants::ROWS_IN_PLAYER_AREA);
}

int MushroomField::GetTotalMushroomCount()
{
	return totalMushroomCount;
}

int MushroomField::GetPlayerAreaMushroomCount()
{
	return playerAreaMushroomCount;
}

Obstacle MushroomField::Inspect(int row, int col)
{
	int ans;
	//0=clear, 1=block, 2=Poison)
	
	if (col < LEFT_COLUMN || col > RIGHT_COLUMN)
		ans = 1;
	else 
	{
		/*if (CentipedeTracker::GetCentipedeTrackerArrayAt(row, col) == true)
		{
			return (Obstacle)1;
		}*/
		Mushroom* mush = MushroomField::CurrentMushroomField->GetMushroomAt(col, row);
		if (mush)
		{
			if (mush->poisoned)
				ans = 2;
			else
				ans = 1;
		}
		else
			ans = 0;
	}

	return (Obstacle)ans;
}

int MushroomField::GetRandomColumn()
{
	return rand() % (GameConstants::COLUMNS - 1);
}

int MushroomField::GetRandomRow()
{
	return rand() % (GameConstants::ROWS - 1);
}

int MushroomField::GetRandomRightOrLeft()
{
	if (rand() % 2 == 0) // right
		return 1;
	else // left
		return -1;
}

const int MushroomField::GetFramesToMoveOneCell(int speed)
{
	return GameConstants::CELLSIZE / speed;
}

bool MushroomField::MushroomCheckAt(int col, int row, MushroomField* mushroomField)
{
	if (mushroomField->GetMushroomAt(col, row) != nullptr)
		return true;
	else
		return false;
}

void MushroomField::Destroy()
{
	/*
	//placing mushrooms randomly in all rows (except bottom one)
	for (int col = 0; col < GameConstants::COLUMNS; col++)
	{
		for (int row = 1; row < GameConstants::ROWS; row++)
		{
			if (GetMushroomAt(col, row) != nullptr)
				GetMushroomAt(col, row)->MarkForDestroy();
		}
	}
	*/
}

void MushroomField::SetField(MushroomField* ActiveMushroomField) 
{
	MushroomField::CurrentMushroomField = ActiveMushroomField;

	// What else do I do to make sure the other MushroomField is “inactive”?
}

MushroomField* MushroomField::CreateNewMushroomField()
{
	MushroomField* newMF = new MushroomField();
	MushroomField::SetField(newMF);
	newMF->Fill();
	return newMF;
}

void MushroomField::SetTotalMushroomCount(int newCount)
{
	totalMushroomCount = newCount;
}
void MushroomField::SetPlayerAreaMushroomCount(int newCount)
{
	playerAreaMushroomCount = newCount;
}

MushroomField::~MushroomField()
{
	//MushroomFactory::Terminate();
}