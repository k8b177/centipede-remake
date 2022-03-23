// FieldManager
// Katherine Burnett, October 2021

#ifndef _FieldManager
#define _FieldManager

#include "MushroomField.h"
#include "GameManager.h"

class GameManager;

class FieldManager {
public:
	// Big Four
	FieldManager() = delete;
	FieldManager(GameManager* gameManager);
	FieldManager(const FieldManager&) = default;
	FieldManager& operator= (const FieldManager&) = default;
	~FieldManager() = default;

	static MushroomField* CurrentMushroomField;

};


#endif _FieldManager
