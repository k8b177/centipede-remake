// MushroomRegen

#ifndef  _MushroomRegen
#define _MushroomRegen

#include "Game Components/TEAL/CommonElements.h"

class CmdScore;
class GridManager;

class MushroomRegen : GameObject
{
public:
	// Big Four
	MushroomRegen() = delete;
	MushroomRegen(const MushroomRegen&) = delete;
	MushroomRegen& operator=(const MushroomRegen&) = delete;
	~MushroomRegen() = default;

	MushroomRegen(GridManager* pGridManager);

	virtual void Alarm0();
	virtual void Alarm1();
	void StartRegen();
	void CheckNextMushroom();

private:
	int r;
	int c;
	CmdScore* pCmdScore;
	GridManager* pGridManager;

};


#endif _MushroomRegen

