#include "MushroomObjectPool.h"
#include "Game Components/TEAL/CommonElements.h"
#include "Mushroom.h"

MushroomObjectPool::MushroomObjectPool()
{

}

MushroomObjectPool::~MushroomObjectPool()
{
	// forcefully delete all recycled gameobjects

	ConsoleMsg::WriteLine("Deleting " + Tools::ToString(recycledItems.size()) + " Mushrooms");
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Mushroom* MushroomObjectPool::GetMushroom()
{
	Mushroom* m;

	if (recycledItems.empty())
	{
		ConsoleMsg::WriteLine("New Mushroom"); // For illustration purposes

		m = new Mushroom();
	}
	else
	{
		ConsoleMsg::WriteLine("Recycled Mushroom"); // For illustration purposes

		m = recycledItems.top();
		recycledItems.pop();	// Remember: top doesn't pop and pop returns void...

		// Tell the object to register itself to the scene
		m->RegisterToCurrentScene();
	}

	return m;
}

void MushroomObjectPool::ReturnMushroom(Mushroom* m)
{
	recycledItems.push(static_cast<Mushroom*>(m));

	// For illustration purposes
	ConsoleMsg::WriteLine("Recycled Stack Size, Mushroom: " + Tools::ToString(recycledItems.size()));

}