#include "AIMoveDirectionDownRight.h"

#include "Blaster.h"

void AIMoveDirectionDownRight::Move(Blaster* b)
{
	b->MoveRight();
	b->MoveDown();
}