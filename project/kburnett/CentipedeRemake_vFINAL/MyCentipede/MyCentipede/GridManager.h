// GridManager

#ifndef _GridManager
#define _GridManager

#include "GridInfo.h"
#include "ObstacleEnum.h"

class Mushroom;
class Player;
class FleaSpawner;
struct TextBlock;
class PlayerManager;

class GridManager
{
public:
	// Big Four
	GridManager();
	GridManager(const GridManager&) = delete;
	GridManager& operator=(const GridManager&) = delete;
	~GridManager() = default;


	void FillCurrentMushroomFieldFromPlayerData(Player* currentPlayer);
	Mushroom* GetMushroomAt(int row, int col);
	TextBlock* GetTextBlockAt(int row, int col);
	void InsertMushroomIntoField(Mushroom* m);
	void InsertTextBlockIntoField(TextBlock* t);
	void RemoveMushroomFromField(Mushroom* m);
	void RemoveTextBlockFromField(TextBlock* t);
	int GetPlayerAreaMushroomCount();
	void SetFleaSpawner(FleaSpawner* pFleaSpawner);

	static Obstacle Inspect(int row, int col);


private:
	Mushroom* CurrentMushroomField[GridInfo::GRID_SIZE];
	TextBlock* TextBlockField[GridInfo::GRID_SIZE];

	int TotalMushroomCount;
	int PlayerAreaMushroomCount;
	FleaSpawner* pFleaSpawner;
	PlayerManager* pPlayerManager;
};


#endif _GridManager

