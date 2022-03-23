// MushroomFieldData

#ifndef _MushroomFieldData
#define _MushroomFieldData

#include "MushroomData.h"
#include "GridInfo.h"

class MushroomFieldData
{
public:
	// Big Four
	MushroomFieldData() = default;
	MushroomFieldData(const MushroomFieldData&) = delete;
	MushroomFieldData& operator=(const MushroomFieldData&) = delete;
	~MushroomFieldData() = default;

	MushroomData GetMushroomDataAt(int i);
	void InitializeMushroomFieldData();
	void SetMushroomDataAtRowCol(int row, int col, bool filled);

private:
	MushroomData myMushroomData[GridInfo::GRID_SIZE];
	bool DropMushroomCheck();

};


#endif _MushroomFieldData

