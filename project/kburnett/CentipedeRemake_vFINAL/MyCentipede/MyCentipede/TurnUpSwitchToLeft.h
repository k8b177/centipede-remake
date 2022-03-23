// TurnUpSwitchToLeft
// Katherine Burnett, October 2021

#include "MoveState.h"

#ifndef _TurnUpSwitchToLeft
#define _TurnUpSwitchToLeft

class MoveState;

class TurnUpSwitchToLeft : public MoveState
{
public:
	TurnUpSwitchToLeft();
	virtual const MoveState* GetNextState(CentipedeHead* chead) const override;
	virtual void PlaceMushroomAhead(int row, int col) const override;
};

#endif _TurnUpSwitchToLeft