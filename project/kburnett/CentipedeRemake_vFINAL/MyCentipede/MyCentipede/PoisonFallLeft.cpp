// PoisonFallLeft

#include "PoisonFallLeft.h"
#include "MoveFSM.h"

PoisonFallLeft::PoisonFallLeft()
{
	MyMoveOffsets = &MovementCollection::MoveOffsets_PoisonFallLeft[0];
}

const MoveState* PoisonFallLeft::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState;

	chead->SetRow(chead->GetRow() - 1);

	if (chead->GetRow() == GridInfo::BOTTOM_ROW)
	{
		chead->SetAnimationToNormal();
		pNextState = &MoveFSM::StateMoveLeftAndUpwards;
	}
	else if (chead->GetRow() == GridInfo::TOP_ROW)
	{
		chead->SetAnimationToNormal();
		pNextState = &MoveFSM::StateMoveLeftAndDownwards;
	}
	else
	{
		pNextState = &MoveFSM::StatePoisonFallLeft;
	}

	return pNextState;
}

void PoisonFallLeft::PlaceMushroomAhead(int row, int col) const
{
	MushroomFactory::CreateMushroom(row - 1, col);
}