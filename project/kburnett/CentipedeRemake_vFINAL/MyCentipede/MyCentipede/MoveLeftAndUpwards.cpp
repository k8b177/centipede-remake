// MoveLeftAndUpwards

#include "MoveLeftAndUpwards.h"
#include "MoveFSM.h"

MoveLeftAndUpwards::MoveLeftAndUpwards()
{
	MyMoveOffsets = &MovementCollection::MoveOffsets_MoveLeftUp[0];
}

const MoveState* MoveLeftAndUpwards::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState;

	chead->SetCol(chead->GetCol() - 1);

	int row = chead->GetRow();
	int col = chead->GetCol() - 1; // looking ahead while left
	Obstacle obst = GridManager::Inspect(row, col);

	if (obst == Obstacle::Clear)
	{
		pNextState = &MoveFSM::StateMoveLeftAndUpwards;
	}
	else if (obst == Obstacle::Blocked) // Edge, shroom or letter?
	{
		if (row == GridInfo::TOP_PLAYER_ROW)
			pNextState = &MoveFSM::StateTurnDownSwitchToRight;
		else
			pNextState = &MoveFSM::StateTurnUpSwitchToRight;
	}
	else
	{
		pNextState = nullptr; // something went wrong
	}


	return pNextState;
}

void MoveLeftAndUpwards::PlaceMushroomAhead(int row, int col) const
{
	MushroomFactory::CreateMushroom(row, col - 1);
}
