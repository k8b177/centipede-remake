// MoveRightAndUpwards
// Katherine Burnett, October 2021

#include "MoveState.h"

#ifndef _MoveRightAndUpwards
#define _MoveRightAndUpwards

class MoveRightAndUpwards : public  MoveState
{
public:
	MoveRightAndUpwards();
	virtual const MoveState* GetNextState(CentipedeHead* chead) const override;
	virtual void PlaceMushroomAhead(int row, int col) const override;
};


#endif _MoveRightAndUpwards
