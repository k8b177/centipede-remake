#include "AIMoveDirectionUpRight.h"

#include "Blaster.h"

void AIMoveDirectionUpRight::Move(Blaster* b)
{
	b->MoveRight();
	b->MoveUp();
}