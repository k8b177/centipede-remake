// TurnDownSwitchToLeft

#include "TurnDownSwitchToLeft.h"
#include "MoveFSM.h"


TurnDownSwitchToLeft::TurnDownSwitchToLeft()
{
	MyMoveOffsets = &MovementCollection::MoveOffsets_TurnDownSwitchToLeft[0];
}

const MoveState* TurnDownSwitchToLeft::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState;

	chead->SetRow(chead->GetRow() - 1);
	// chead->FlipSpriteDirection();

	int row = chead->GetRow();
	int col = chead->GetCol() - 1; // looking ahead after turn ->left
	Obstacle obst = GridManager::Inspect(row, col);

	if (obst == Obstacle::Clear)
	{
		pNextState = &MoveFSM::StateMoveLeftAndDownwards;
	}
	else if (obst == Obstacle::Blocked) // Edge, shroom or letter?
	{
		if (row != GridInfo::BOTTOM_ROW)
			pNextState = &MoveFSM::StateTurnDownSwitchToRight;
		else
			pNextState = &MoveFSM::StateTurnUpSwitchToRight;
	}
	else // poison
	{
		chead->SetAnimationToPoison();
		pNextState = &MoveFSM::StatePoisonFallLeft;
	}


	return pNextState;
}

void TurnDownSwitchToLeft::PlaceMushroomAhead(int row, int col) const
{
	MushroomFactory::CreateMushroom(row - 1, col - 1);
}