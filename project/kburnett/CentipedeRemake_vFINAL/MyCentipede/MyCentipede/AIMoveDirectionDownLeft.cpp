#include "AIMoveDirectionDownLeft.h"

#include "Blaster.h"

void AIMoveDirectionDownLeft::Move(Blaster* b)
{
	b->MoveLeft();
	b->MoveDown();
}