#ifndef _FrozenControllerMode
#define _FrozenControllerMode

#include "ControllerMode.h"

class FrozenControllerMode : public ControllerMode
{
public:
	FrozenControllerMode();
	FrozenControllerMode(const FrozenControllerMode&) = delete;
	FrozenControllerMode& operator= (const FrozenControllerMode&) = delete;
	~FrozenControllerMode() = default;

	void MovementUpdate() override;

	Blaster* blaster;

private:

};

#endif _FrozenControllerMode