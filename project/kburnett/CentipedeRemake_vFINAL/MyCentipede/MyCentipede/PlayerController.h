#ifndef _PlayerController
#define _PlayerController

#include "Game Components/TEAL/CommonElements.h"

class ControllerMode;
class AIControllerMode;
class KeyboardControllerMode;
class FrozenControllerMode;

class PlayerController : public GameObject
{
public:
	PlayerController();
	PlayerController(const PlayerController&) = delete;
	PlayerController& operator= (const PlayerController&) = delete;
	~PlayerController();

	virtual void Update();
	void SetCurrentControllerMode(ControllerMode* newControllerMode);


	AIControllerMode* AIStrategy;
	KeyboardControllerMode* KeyboardStrategy;
	FrozenControllerMode* FrozenStrategy;

private:
	ControllerMode* CurrentControllerMode;
};

#endif _Player