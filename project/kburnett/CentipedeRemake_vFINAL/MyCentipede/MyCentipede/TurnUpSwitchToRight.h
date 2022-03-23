// TurnUpSwitchToRight
// Katherine Burnett, October 2021

#include "MoveState.h"

#ifndef _TurnUpSwitchToRight
#define _TurnUpSwitchToRight

class MoveState;

class TurnUpSwitchToRight : public  MoveState
{
public:
	TurnUpSwitchToRight();
	virtual const MoveState* GetNextState(CentipedeHead* chead) const override;
	virtual void PlaceMushroomAhead(int row, int col) const override;
};

#endif _TurnUpSwitchToRight