#include "AIControllerMode.h"

#include "AIMoveDirectionDownLeft.h"
#include "AIMoveDirectionDownRight.h"
#include "AIMoveDirectionUpLeft.h"
#include "AIMoveDirectionUpRight.h"
#include "AIMoveDirection_Stop.h"

#include "BlasterFactory.h"
#include "Blaster.h"

AIControllerMode::AIControllerMode()
{
	blaster = BlasterFactory::GetBlaster();

	countToChangeDirection = 60;

	counter = 0;

	pStop = new AIMoveDirectionStop();
	pDownLeft = new AIMoveDirectionDownLeft();
	pDownRight = new AIMoveDirectionDownRight();
	pUpLeft = new AIMoveDirectionUpLeft();
	pUpRight = new AIMoveDirectionUpRight();

	currMoveDirection = pStop;
}

void AIControllerMode::MovementUpdate()
{
	if (counter >= countToChangeDirection)
	{
		ChangeDirection();
		counter = 0;
	}
	
	currMoveDirection->Move(blaster);

	blaster->Fire();

	counter++;
}

void AIControllerMode::ChangeDirection()
{
	int n = rand() % 4;
	switch (n) {
	case 0:
		currMoveDirection = pStop;
		break;
	case 1:
		currMoveDirection = pDownLeft;
		break;
	case 2:
		currMoveDirection = pDownRight;
		break;
	case 3:
		currMoveDirection = pUpLeft;
		break;
	case 4:
		currMoveDirection = pUpRight;
		break;
	}
}

AIControllerMode::~AIControllerMode()
{
	delete pStop;
	delete pDownLeft;
	delete pDownRight;
	delete pUpLeft;
	delete pUpRight;
}