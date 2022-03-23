// TurnUpSwitchToLeft

#include "TurnUpSwitchToLeft.h"
#include "MoveFSM.h"

TurnUpSwitchToLeft::TurnUpSwitchToLeft()
{
	MyMoveOffsets = &MovementCollection::MoveOffsets_TurnUpSwitchToLeft[0];
}

const MoveState* TurnUpSwitchToLeft::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState;

	chead->SetRow(chead->GetRow() + 1);
	// chead->FlipSpriteDirection();

	int row = chead->GetRow();
	int col = chead->GetCol() - 1; // looking ahead after turn -> left
	Obstacle obst = GridManager::Inspect(row, col);

	if (obst == Obstacle::Clear)
	{
		pNextState = &MoveFSM::StateMoveLeftAndUpwards;
	}
	else if (obst == Obstacle::Blocked) // Edge, shroom or letter?
	{
		if (row != GridInfo::TOP_PLAYER_ROW)
			pNextState = &MoveFSM::StateTurnUpSwitchToRight;
		else
			pNextState = &MoveFSM::StateTurnDownSwitchToRight;
	}
	else
	{
		pNextState = nullptr; // something went wrong
	}


	return pNextState;
}

void TurnUpSwitchToLeft::PlaceMushroomAhead(int row, int col) const
{
	MushroomFactory::CreateMushroom(row + 1, col - 1);
}