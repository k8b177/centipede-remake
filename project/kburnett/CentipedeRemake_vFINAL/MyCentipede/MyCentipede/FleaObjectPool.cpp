#include "FleaObjectPool.h"
#include "Game Components/TEAL/CommonElements.h"
#include "Flea.h"

FleaObjectPool::FleaObjectPool()
{

}

FleaObjectPool::~FleaObjectPool()
{
	// forcefully delele all recycled gameobjects

	ConsoleMsg::WriteLine("Deleting " + Tools::ToString(recycledItems.size()) + " Fleas");
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Flea* FleaObjectPool::GetFlea()
{
	Flea* f;

	if (recycledItems.empty())
	{
		ConsoleMsg::WriteLine("New Flea"); // For illustration purposes

		f = new Flea();
	}
	else
	{
		ConsoleMsg::WriteLine("Recycled Flea"); // For illustration purposes

		f = recycledItems.top();
		recycledItems.pop();	// Remember: top doesn't pop and pop returns void...

		// Tell the object to register itself to the scene
		f->RegisterToCurrentScene();
	}

	return f;
}

void FleaObjectPool::ReturnFlea(Flea* f)
{
	recycledItems.push(static_cast<Flea*>(f));

	// For illustration purposes
	ConsoleMsg::WriteLine("Recycled Stack Size, Flea: " + Tools::ToString(recycledItems.size()));
}