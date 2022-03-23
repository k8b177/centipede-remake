#ifndef _ControllerMode
#define _ControllerMode

class Blaster;

class ControllerMode
{
public:
	ControllerMode() = default;
	ControllerMode(const ControllerMode&) = delete;
	ControllerMode& operator= (const ControllerMode&) = delete;
	~ControllerMode() = default;

	virtual void MovementUpdate() = 0;

private:
};

#endif _ControllerMode