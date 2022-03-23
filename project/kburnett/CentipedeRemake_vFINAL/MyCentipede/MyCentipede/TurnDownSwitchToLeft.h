// TurnDownSwitchToLeft
// Katherine Burnett, October 2021

#include "MoveState.h"

#ifndef _TurnDownSwitchToLeft
#define _TurnDownSwitchToLeft

class TurnDownSwitchToLeft : public MoveState
{
public:
	TurnDownSwitchToLeft();
	virtual const MoveState* GetNextState(CentipedeHead* chead) const override;
	virtual void PlaceMushroomAhead(int row, int col) const override;
};

#endif _TurnDownSwitchToLeft