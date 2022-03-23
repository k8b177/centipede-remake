// PoisonFallRight

#include "PoisonFallRight.h"
#include "MoveFSM.h"

PoisonFallRight::PoisonFallRight()
{
	MyMoveOffsets = &MovementCollection::MoveOffsets_PoisonFallRight[0];
}

const MoveState* PoisonFallRight::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState;

	chead->SetRow(chead->GetRow() - 1);

	if (chead->GetRow() == GridInfo::BOTTOM_ROW)
	{
		chead->SetAnimationToNormal();
		pNextState = &MoveFSM::StateMoveRightAndUpwards;
	}
	else if (chead->GetRow() == GridInfo::TOP_ROW)
	{
		chead->SetAnimationToNormal();
		pNextState = &MoveFSM::StateMoveRightAndDownwards;
	}
	else
	{
		pNextState = &MoveFSM::StatePoisonFallRight;
	}

	return pNextState;
}

void PoisonFallRight::PlaceMushroomAhead(int row, int col) const
{
	MushroomFactory::CreateMushroom(row - 1, col);
}