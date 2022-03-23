#include "MoveState.h"

MoveState::MoveState()
	:MyMoveOffsets(nullptr)
{

}

const MoveOffset* MoveState::GetMoveOffsets() const
{ 
	return MyMoveOffsets; 
}