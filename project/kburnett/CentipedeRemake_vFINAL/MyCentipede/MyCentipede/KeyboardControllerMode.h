#ifndef _KeyboardControllerMode
#define _KeyboardControllerMode

#include "ControllerMode.h"

#include "Game Components/TEAL/CommonElements.h"

class KeyboardControllerMode : public ControllerMode
{
public:
	KeyboardControllerMode();
	KeyboardControllerMode(const KeyboardControllerMode&) = delete;
	KeyboardControllerMode& operator= (const KeyboardControllerMode&) = delete;
	~KeyboardControllerMode() = default;

	void MovementUpdate() override;

	Blaster* blaster;

private:
	sf::Keyboard::Key UP;
	sf::Keyboard::Key DOWN;
	sf::Keyboard::Key LEFT;
	sf::Keyboard::Key RIGHT;
	sf::Keyboard::Key FIRE;
};

#endif _KeyboardControllerMode