// TurnDownSwitchToRight
// Katherine Burnett, October 2021

#include "MoveState.h"

#ifndef _TurnDownSwitchToRight
#define _TurnDownSwitchToRight


class TurnDownSwitchToRight : public  MoveState
{
public:
	TurnDownSwitchToRight();
	virtual const MoveState* GetNextState(CentipedeHead* chead) const override;
	virtual void PlaceMushroomAhead(int row, int col) const override;
};

#endif _TurnDownSwitchToRight