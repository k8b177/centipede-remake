// MoveLeftAndDownwards

#include "MoveLeftAndDownwards.h"
#include "MoveFSM.h"


MoveLeftAndDownwards::MoveLeftAndDownwards()
{
	MyMoveOffsets = &MovementCollection::MoveOffsets_MoveLeftDown[0];
}

const MoveState* MoveLeftAndDownwards::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState;


	chead->SetCol(chead->GetCol() - 1);

	int row = chead->GetRow();
	int col = chead->GetCol() - 1; // looking ahead while left
	Obstacle obst = GridManager::Inspect(row, col);

	if (obst == Obstacle::Clear)
	{
		pNextState = &MoveFSM::StateMoveLeftAndDownwards;
	}
	else if (obst == Obstacle::Blocked) // Edge, shroom or letter?
	{
		if (row == GridInfo::BOTTOM_ROW)
			pNextState = &MoveFSM::StateTurnUpSwitchToRight;
		else
			pNextState = &MoveFSM::StateTurnDownSwitchToRight;
	}
	else // poison
	{
		chead->SetAnimationToPoison();
		pNextState = &MoveFSM::StatePoisonFallLeft;
	}


	return pNextState;
}

void MoveLeftAndDownwards::PlaceMushroomAhead(int row, int col) const
{
	MushroomFactory::CreateMushroom(row, col - 1);
}