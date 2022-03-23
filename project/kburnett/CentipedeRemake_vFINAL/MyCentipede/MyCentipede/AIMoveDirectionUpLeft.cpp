#include "AIMoveDirectionUpLeft.h"

#include "Blaster.h"

void AIMoveDirectionUpLeft::Move(Blaster* b)
{
	b->MoveLeft();
	b->MoveUp();
}