// MovementCollection
// Katherine Burnett, October 2021

#include "GridInfo.h"

#ifndef _MovementCollection
#define _MovementCollection


struct MoveOffset
{
	int xOffset;
	int yOffset;
	float angle;

	MoveOffset(int x, int y, float a) : xOffset(x), yOffset(y), angle(a) {};
};


class MovementCollection
{
public:
	static const MoveOffset MoveOffsets_MoveRightDown[GridInfo::CELLSIZE];
	static const MoveOffset MoveOffsets_MoveRightUp[GridInfo::CELLSIZE];
	static const MoveOffset MoveOffsets_MoveLeftDown[GridInfo::CELLSIZE];
	static const MoveOffset MoveOffsets_MoveLeftUp[GridInfo::CELLSIZE];
	static const MoveOffset MoveOffsets_TurnDownSwitchToLeft[GridInfo::CELLSIZE];
	static const MoveOffset MoveOffsets_TurnDownSwitchToRight[GridInfo::CELLSIZE];
	static const MoveOffset MoveOffsets_TurnUpSwitchToLeft[GridInfo::CELLSIZE];
	static const MoveOffset MoveOffsets_TurnUpSwitchToRight[GridInfo::CELLSIZE];
	static const MoveOffset MoveOffsets_PoisonFallLeft[GridInfo::CELLSIZE];
	static const MoveOffset MoveOffsets_PoisonFallRight[GridInfo::CELLSIZE];
};
#endif _MovementCollection
