// MoveLeftAndDownwards
// Katherine Burnett, October 2021

#include "MoveState.h"

#ifndef _MoveLeftAndDownwards
#define _MoveLeftAndDownwards

class MoveLeftAndDownwards : public MoveState
{
public:
	MoveLeftAndDownwards();
	virtual const MoveState* GetNextState(CentipedeHead* chead) const override;
	virtual void PlaceMushroomAhead(int row, int col) const override;
};

#endif _MoveLeftAndDownwards
