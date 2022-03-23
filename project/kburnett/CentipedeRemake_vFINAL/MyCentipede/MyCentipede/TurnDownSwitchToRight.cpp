// TurnDownSwitchToRight

#include "TurnDownSwitchToRight.h"
#include "MoveFSM.h"

TurnDownSwitchToRight::TurnDownSwitchToRight()
{
	MyMoveOffsets = &MovementCollection::MoveOffsets_TurnDownSwitchToRight[0];
}

const MoveState* TurnDownSwitchToRight::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState;

	chead->SetRow(chead->GetRow() - 1);
	// chead->FlipSpriteDirection();

	int row = chead->GetRow();
	int col = chead->GetCol() + 1; // looking ahead after turn -> right
	Obstacle obst = GridManager::Inspect(row, col);

	if (obst == Obstacle::Clear)
	{
		pNextState = &MoveFSM::StateMoveRightAndDownwards;
	}
	else if (obst == Obstacle::Blocked) // Edge, shroom or letter?
	{
		if (row >= GridInfo::BOTTOM_ROW)
			pNextState = &MoveFSM::StateTurnDownSwitchToLeft;
		else
			pNextState = &MoveFSM::StateTurnUpSwitchToLeft;
	}
	else // poison
	{
		chead->SetAnimationToPoison();
		pNextState = &MoveFSM::StatePoisonFallRight;
	}

	

	return pNextState;
}

void TurnDownSwitchToRight::PlaceMushroomAhead(int row, int col) const
{
	MushroomFactory::CreateMushroom(row - 1, col + 1);
}
