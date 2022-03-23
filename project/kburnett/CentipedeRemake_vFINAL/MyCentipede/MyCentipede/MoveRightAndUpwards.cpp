// MoveRightAndUpwards

#include "MoveRightAndUpwards.h"
#include "MoveFSM.h"

MoveRightAndUpwards::MoveRightAndUpwards()
{
	MyMoveOffsets = &MovementCollection::MoveOffsets_MoveRightUp[0];
}

const MoveState* MoveRightAndUpwards::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState;

	chead->SetCol(chead->GetCol() + 1);

	int row = chead->GetRow();
	int col = chead->GetCol() + 1; // looking ahead while right
	Obstacle obst = GridManager::Inspect(row, col);

	if (obst == Obstacle::Clear)
	{
		pNextState = &MoveFSM::StateMoveRightAndUpwards;
	}
	else if (obst == Obstacle::Blocked) // Edge, shroom or letter?
	{
		if (row == GridInfo::TOP_PLAYER_ROW)
			pNextState = &MoveFSM::StateTurnDownSwitchToLeft;
		else
			pNextState = &MoveFSM::StateTurnUpSwitchToLeft;
	}
	else
	{
		pNextState = nullptr; // something went wrong
	}

	return pNextState;
}

void MoveRightAndUpwards::PlaceMushroomAhead(int row, int col) const
{
	MushroomFactory::CreateMushroom(row, col + 1);
}