// MoveRightAndDownwards
// Katherine Burnett, October 2021

#include "MoveState.h"

#ifndef _MoveRightAndDownwards
#define _MoveRightAndDownwards

class MoveRightAndDownwards : public MoveState
{
public:
	MoveRightAndDownwards();
	virtual const MoveState* GetNextState(CentipedeHead* chead) const override;
	virtual void PlaceMushroomAhead(int row, int col) const override;
};

#endif _MoveRightAndDownwards
