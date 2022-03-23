// AttractorController

#ifndef _AttractorController
#define _AttractorController

#include "Game Components/TEAL/CommonElements.h"

class AttractorController : public GameObject
{
public:
	// Big Four
	AttractorController();
	AttractorController(const AttractorController&) = default;
	AttractorController& operator= (const AttractorController&) = default;
	~AttractorController();

	virtual void KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey);
	virtual void Destroy();

private:
};

#endif _Attractor
