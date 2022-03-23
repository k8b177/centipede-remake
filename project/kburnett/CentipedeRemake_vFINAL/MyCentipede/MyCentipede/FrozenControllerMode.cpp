#include "FrozenControllerMode.h"

#include "BlasterFactory.h"
#include "Blaster.h"

FrozenControllerMode::FrozenControllerMode()
{
	blaster = BlasterFactory::GetBlaster();
}

void FrozenControllerMode::MovementUpdate()
{
	// do nothing
}