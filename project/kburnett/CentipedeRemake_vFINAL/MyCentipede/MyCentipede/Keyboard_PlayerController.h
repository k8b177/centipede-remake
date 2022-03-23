// Keyboard_ PlayerController
// Katherine Burnett, September 2021

#ifndef _Keyboard_PlayerController
#define _Keyboard_PlayerController

#include "../MyCentipede/Game Components/TEAL/CommonElements.h"
#include "Blaster.h"

class Blaster;

class Keyboard_PlayerController: public GameObject
{
public:
	// Big Four
	Keyboard_PlayerController() = default;
	Keyboard_PlayerController(const Keyboard_PlayerController&) = default;
	Keyboard_PlayerController& operator= (const Keyboard_PlayerController&) = default;
	~Keyboard_PlayerController();

	Keyboard_PlayerController(Blaster* blaster);

	virtual void Update();
private:
	sf::Keyboard::Key UP;
	sf::Keyboard::Key DOWN;
	sf::Keyboard::Key LEFT;
	sf::Keyboard::Key RIGHT;
	sf::Keyboard::Key FIRE;

	Blaster* blaster;

};

#endif _Keyboard_PlayerController
