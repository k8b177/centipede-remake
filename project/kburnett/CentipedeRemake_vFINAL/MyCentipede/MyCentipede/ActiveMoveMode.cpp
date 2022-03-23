#include "ActiveMoveMode.h"

#include "Critter.h"

void ActiveMoveMode::MoveUpdate(Critter* c)
{
	c->MoveUpdate();
}