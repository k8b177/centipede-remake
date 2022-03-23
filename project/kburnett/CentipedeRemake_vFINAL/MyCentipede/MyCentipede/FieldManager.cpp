// FieldManager

#include "FieldManager.h"


MushroomField* FieldManager::CurrentMushroomField = nullptr;

FieldManager::FieldManager(GameManager* gameManager)
{
	CurrentMushroomField = new MushroomField();
}