// TurnUpSwitchToRight

#include "TurnUpSwitchToRight.h"
#include "MoveFSM.h"

TurnUpSwitchToRight::TurnUpSwitchToRight()
{
	MyMoveOffsets = &MovementCollection::MoveOffsets_TurnUpSwitchToRight[0];
}

const MoveState* TurnUpSwitchToRight::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState;

	chead->SetRow(chead->GetRow() + 1);
	// chead->FlipSpriteDirection();

	int row = chead->GetRow();
	int col = chead->GetCol() + 1; // looking ahead after turn -> Right
	Obstacle obst = GridManager::Inspect(row, col);

	if (obst == Obstacle::Clear)
	{
		pNextState = &MoveFSM::StateMoveRightAndUpwards;
	}
	else if (obst == Obstacle::Blocked) // Edge, shroom or letter?
	{
		if (row != GridInfo::TOP_PLAYER_ROW)
			pNextState = &MoveFSM::StateTurnUpSwitchToLeft;
		else
			pNextState = &MoveFSM::StateTurnDownSwitchToLeft;
	}
	else
	{
		pNextState = nullptr; // something went wrong
	}


	return pNextState;
}

void TurnUpSwitchToRight::PlaceMushroomAhead(int row, int col) const
{
	MushroomFactory::CreateMushroom(row + 1, col + 1);
}
