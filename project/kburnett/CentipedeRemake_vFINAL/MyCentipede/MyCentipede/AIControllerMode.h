#ifndef _AIControllerMode
#define _AIControllerMode

#include "ControllerMode.h"

class AIMoveDirection;
class AIMoveDirectionStop;
class AIMoveDirectionDownLeft;
class AIMoveDirectionDownRight;
class AIMoveDirectionUpLeft;
class AIMoveDirectionUpRight;

class AIControllerMode : public ControllerMode
{
public:
	AIControllerMode();
	AIControllerMode(const AIControllerMode&) = delete;
	AIControllerMode& operator= (const AIControllerMode&) = delete;
	~AIControllerMode();

	void MovementUpdate() override;

	Blaster* blaster;

private:
	AIMoveDirection* currMoveDirection;
	AIMoveDirectionStop* pStop;
	AIMoveDirectionDownLeft* pDownLeft;
	AIMoveDirectionDownRight* pDownRight;
	AIMoveDirectionUpLeft* pUpLeft;
	AIMoveDirectionUpRight* pUpRight;

	int counter;
	int countToChangeDirection;

	void ChangeDirection();
};

#endif _AIControllerMode