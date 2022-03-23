// MoveRightAndDownwards

#include "MoveRightAndDownwards.h"
#include "MoveFSM.h"

MoveRightAndDownwards::MoveRightAndDownwards()
{
	MyMoveOffsets = &MovementCollection::MoveOffsets_MoveRightDown[0];
}
const MoveState* MoveRightAndDownwards::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState;

	chead->SetCol(chead->GetCol() + 1);

	int row = chead->GetRow();
	int col = chead->GetCol() + 1; // looking ahead while right
	Obstacle obst = GridManager::Inspect(row, col);

	if (obst == Obstacle::Clear)
	{
		pNextState = &MoveFSM::StateMoveRightAndDownwards;
	}
	else if (obst == Obstacle::Blocked) // Edge, shroom or letter?
	{
		if (row == GridInfo::BOTTOM_ROW)
			pNextState = &MoveFSM::StateTurnUpSwitchToLeft;
		else
			pNextState = &MoveFSM::StateTurnDownSwitchToLeft;
	}
	else // poison
	{
		chead->SetAnimationToPoison();
		pNextState = &MoveFSM::StatePoisonFallRight;
	}


	return pNextState;
}

void MoveRightAndDownwards::PlaceMushroomAhead(int row, int col) const
{
	MushroomFactory::CreateMushroom(row, col + 1);
}