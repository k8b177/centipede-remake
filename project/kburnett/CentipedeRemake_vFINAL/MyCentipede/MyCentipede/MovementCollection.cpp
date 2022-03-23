// MovementCollection

#include "MovementCollection.h"

const MoveOffset MovementCollection::MoveOffsets_MoveRightDown[GridInfo::CELLSIZE] =
{
	MoveOffset(1, 0, 180.0f),
	MoveOffset(2, 0, 180.0f),
	MoveOffset(3, 0, 180.0f),
	MoveOffset(4, 0, 180.0f),
	MoveOffset(5, 0, 180.0f),
	MoveOffset(6, 0, 180.0f),
	MoveOffset(7, 0, 180.0f),
	MoveOffset(8, 0, 180.0f),
	MoveOffset(9, 0, 180.0f),
	MoveOffset(10, 0, 180.0f),
	MoveOffset(11, 0, 180.0f),
	MoveOffset(12, 0, 180.0f),
	MoveOffset(13, 0, 180.0f),
	MoveOffset(14, 0, 180.0f),
	MoveOffset(15, 0, 180.0f),
	MoveOffset(16, 0, 180.0f)
};
const MoveOffset MovementCollection::MoveOffsets_MoveRightUp[GridInfo::CELLSIZE] =
{
	MoveOffset(1, 0, 180.0f),
	MoveOffset(2, 0, 180.0f),
	MoveOffset(3, 0, 180.0f),
	MoveOffset(4, 0, 180.0f),
	MoveOffset(5, 0, 180.0f),
	MoveOffset(6, 0, 180.0f),
	MoveOffset(7, 0, 180.0f),
	MoveOffset(8, 0, 180.0f),
	MoveOffset(9, 0, 180.0f),
	MoveOffset(10, 0, 180.0f),
	MoveOffset(11, 0, 180.0f),
	MoveOffset(12, 0, 180.0f),
	MoveOffset(13, 0, 180.0f),
	MoveOffset(14, 0, 180.0f),
	MoveOffset(15, 0, 180.0f),
	MoveOffset(16, 0, 180.0f)
};
const MoveOffset MovementCollection::MoveOffsets_MoveLeftDown[GridInfo::CELLSIZE] =
{
	MoveOffset(-1, 0, 0.0f),
	MoveOffset(-2, 0, 0.0f),
	MoveOffset(-3, 0, 0.0f),
	MoveOffset(-4, 0, 0.0f),
	MoveOffset(-5, 0, 0.0f),
	MoveOffset(-6, 0, 0.0f),
	MoveOffset(-7, 0, 0.0f),
	MoveOffset(-8, 0, 0.0f),
	MoveOffset(-9, 0, 0.0f),
	MoveOffset(-10, 0, 0.0f),
	MoveOffset(-11, 0, 0.0f),
	MoveOffset(-12, 0, 0.0f),
	MoveOffset(-13, 0, 0.0f),
	MoveOffset(-14, 0, 0.0f),
	MoveOffset(-15, 0, 0.0f),
	MoveOffset(-16, 0, 0.0f)
};
const MoveOffset MovementCollection::MoveOffsets_MoveLeftUp[GridInfo::CELLSIZE] =
{
	MoveOffset(-1, 0, 0.0f),
	MoveOffset(-2, 0, 0.0f),
	MoveOffset(-3, 0, 0.0f),
	MoveOffset(-4, 0, 0.0f),
	MoveOffset(-5, 0, 0.0f),
	MoveOffset(-6, 0, 0.0f),
	MoveOffset(-7, 0, 0.0f),
	MoveOffset(-8, 0, 0.0f),
	MoveOffset(-9, 0, 0.0f),
	MoveOffset(-10, 0, 0.0f),
	MoveOffset(-11, 0, 0.0f),
	MoveOffset(-12, 0, 0.0f),
	MoveOffset(-13, 0, 0.0f),
	MoveOffset(-14, 0, 0.0f),
	MoveOffset(-15, 0, 0.0f),
	MoveOffset(-16, 0, 0.0f)
};
const MoveOffset MovementCollection::MoveOffsets_TurnDownSwitchToLeft[GridInfo::CELLSIZE] =
{
	MoveOffset(0, 1, 1 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT + 180),
	MoveOffset(0, 2, 2 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT + 180),
	MoveOffset(0, 3, 3 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT + 180),
	MoveOffset(0, 4, 4 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT + 180),
	MoveOffset(0, 5, 5 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT + 180),
	MoveOffset(0, 6, 6 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT + 180),
	MoveOffset(0, 7, 7 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT + 180),
	MoveOffset(0, 8, 8 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT + 180),
	MoveOffset(0, 9, 9 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT + 180),
	MoveOffset(0, 10, 10 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT + 180),
	MoveOffset(0, 11, 11 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT + 180),
	MoveOffset(0, 12, 12 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT + 180),
	MoveOffset(0, 13, 13 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT + 180),
	MoveOffset(0, 14, 14 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT + 180),
	MoveOffset(0, 15, 15 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT + 180),
	MoveOffset(0, 16, 16 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT + 180)
};
const MoveOffset MovementCollection::MoveOffsets_TurnDownSwitchToRight[GridInfo::CELLSIZE]
{
	MoveOffset(0, 1, 360 - 1 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT),
	MoveOffset(0, 2, 360 - 2 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT),
	MoveOffset(0, 3, 360 - 3 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT),
	MoveOffset(0, 4, 360 - 4 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT),
	MoveOffset(0, 5, 360 - 5 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT),
	MoveOffset(0, 6, 360 - 6 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT),
	MoveOffset(0, 7, 360 - 7 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT),
	MoveOffset(0, 8, 360 - 8 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT),
	MoveOffset(0, 9, 360 - 9 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT),
	MoveOffset(0, 10, 360 - 10 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT),
	MoveOffset(0, 11, 360 - 11 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT),
	MoveOffset(0, 12, 360 - 12 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT),
	MoveOffset(0, 13, 360 - 13 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT),
	MoveOffset(0, 14, 360 - 14 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT),
	MoveOffset(0, 15, 360 - 15 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT),
	MoveOffset(0, 16, 360 - 16 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT)
};
const MoveOffset MovementCollection::MoveOffsets_TurnUpSwitchToLeft[GridInfo::CELLSIZE] =
{
	MoveOffset(0, -1, 360 - (1 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT + 180)),
	MoveOffset(0, -2, 360 - (2 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT + 180)),
	MoveOffset(0, -3, 360 - (3 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT + 180)),
	MoveOffset(0, -4, 360 - (4 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT + 180)),
	MoveOffset(0, -5, 360 - (5 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT + 180)),
	MoveOffset(0, -6, 360 - (6 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT + 180)),
	MoveOffset(0, -7, 360 - (7 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT + 180)),
	MoveOffset(0, -8, 360 - (8 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT + 180)),
	MoveOffset(0, -9, 360 - (9 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT + 180)),
	MoveOffset(0, -10, 360 - (10 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT + 180)),
	MoveOffset(0, -11, 360 - (11 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT + 180)),
	MoveOffset(0, -12, 360 - (12 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT + 180)),
	MoveOffset(0, -13, 360 - (13 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT + 180)),
	MoveOffset(0, -14, 360 - (14 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT + 180)),
	MoveOffset(0, -15, 360 - (15 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT + 180)),
	MoveOffset(0, -16, 360 - (16 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT + 180))
};
const MoveOffset MovementCollection::MoveOffsets_TurnUpSwitchToRight[GridInfo::CELLSIZE] =
{
	MoveOffset(0, -1, 1 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT),
	MoveOffset(0, -2, 2 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT),
	MoveOffset(0, -3, 3 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT),
	MoveOffset(0, -4, 4 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT),
	MoveOffset(0, -5, 5 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT),
	MoveOffset(0, -6, 6 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT),
	MoveOffset(0, -7, 7 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT),
	MoveOffset(0, -8, 8 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT),
	MoveOffset(0, -9, 9 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT),
	MoveOffset(0, -10, 10 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT),
	MoveOffset(0, -11, 11 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT),
	MoveOffset(0, -12, 12 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT),
	MoveOffset(0, -13, 13 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT),
	MoveOffset(0, -14, 14 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT),
	MoveOffset(0, -15, 15 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT),
	MoveOffset(0, -16, 16 * GameConstants::CENTIPEDETURN_ANGLEINCREMENT)
};

const MoveOffset MovementCollection::MoveOffsets_PoisonFallLeft[GridInfo::CELLSIZE] =
{
	MoveOffset(1, 1, 270.0f),
	MoveOffset(2, 2, 270.0f),
	MoveOffset(3, 3, 270.0f),
	MoveOffset(4, 4, 270.0f),
	MoveOffset(5, 5, 270.0f),
	MoveOffset(6, 6, 270.0f),
	MoveOffset(7, 7, 270.0f),
	MoveOffset(8, 8, 270.0f),
	MoveOffset(7, 9, 270.0f),
	MoveOffset(6, 10, 270.0f),
	MoveOffset(5, 11, 270.0f),
	MoveOffset(4, 12, 270.0f),
	MoveOffset(3, 13, 270.0f),
	MoveOffset(2, 14, 270.0f),
	MoveOffset(1, 15, 270.0f),
	MoveOffset(0, 16, 270.0f)
};

const MoveOffset MovementCollection::MoveOffsets_PoisonFallRight[GridInfo::CELLSIZE] =
{
	MoveOffset(1, 1, 270.0f),
	MoveOffset(2, 2, 270.0f),
	MoveOffset(3, 3, 270.0f),
	MoveOffset(4, 4, 270.0f),
	MoveOffset(5, 5, 270.0f),
	MoveOffset(6, 6, 270.0f),
	MoveOffset(7, 7, 270.0f),
	MoveOffset(8, 8, 270.0f),
	MoveOffset(7, 9, 270.0f),
	MoveOffset(6, 10, 270.0f),
	MoveOffset(5, 11, 270.0f),
	MoveOffset(4, 12, 270.0f),
	MoveOffset(3, 13, 270.0f),
	MoveOffset(2, 14, 270.0f),
	MoveOffset(1, 15, 270.0f),
	MoveOffset(0, 16, 270.0f)
};