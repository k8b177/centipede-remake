// Critter Base class for all critters

#ifndef _Critter
#define _Critter

#include "Game Components/TEAL/CommonElements.h"

class Critter : public GameObject
{
public:
	// Big Four
	Critter() = default;
	Critter(const Critter&) = delete;
	Critter& operator=(const Critter&) = delete;
	~Critter() = default;

	virtual void MoveUpdate() = 0;
};

#endif _Critter
