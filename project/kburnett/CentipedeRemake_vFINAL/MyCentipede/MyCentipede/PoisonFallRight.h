// PoisonFallRight
// Katherine Burnett, October 2021

#include "MoveState.h"

#ifndef _PoisonFallRight
#define _PoisonFallRight

class PoisonFallRight : public  MoveState
{
public:
	PoisonFallRight();
	virtual const MoveState* GetNextState(CentipedeHead* chead) const override;
	virtual void PlaceMushroomAhead(int row, int col) const override;
};


#endif _PoisonFallRight

