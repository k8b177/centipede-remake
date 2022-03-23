// MoveState
// Katherine Burnett, October 2021

#ifndef _MoveState
#define _MoveState

#include "MovementCollection.h"
#include "MushroomFactory.h"
#include "GridManager.h"

struct MoveOffset;
class CentipedeHead;

class MoveState
{
public:
	MoveState();
	const MoveOffset* GetMoveOffsets() const;
	virtual const MoveState* GetNextState(CentipedeHead* chead) const = 0;
	virtual void PlaceMushroomAhead(int row, int col) const = 0;

protected:
	const MoveOffset* MyMoveOffsets;
};

#endif _MoveState
