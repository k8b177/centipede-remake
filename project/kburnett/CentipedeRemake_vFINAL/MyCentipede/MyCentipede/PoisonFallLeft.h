// PoisonFallLeft
// Katherine Burnett, October 2021

#include "MoveState.h"

#ifndef _PoisonFallLeft
#define _PoisonFallLeft

class PoisonFallLeft : public  MoveState
{
public:
	PoisonFallLeft();
	virtual const MoveState* GetNextState(CentipedeHead* chead) const override;
	virtual void PlaceMushroomAhead(int row, int col) const override;
};


#endif _MoveRightAndUpwards

