// MoveLeftAndUpwards
// Katherine Burnett, October 2021

#include "MoveState.h"

#ifndef _MoveLeftAndUpwards
#define _MoveLeftAndUpwards

class MoveLeftAndUpwards : public MoveState
{
public:
	MoveLeftAndUpwards();
	virtual const MoveState* GetNextState(CentipedeHead* chead) const override;
	virtual void PlaceMushroomAhead(int row, int col) const override;
};

#endif _MoveLeftAndUpwards
