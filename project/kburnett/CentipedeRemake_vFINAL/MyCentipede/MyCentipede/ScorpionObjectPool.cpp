#include "ScorpionObjectPool.h"
#include "Game Components/TEAL/CommonElements.h"
#include "Scorpion.h"

ScorpionObjectPool::ScorpionObjectPool()
{

}

ScorpionObjectPool::~ScorpionObjectPool()
{
	// forcefully delele all recycled gameobjects

	ConsoleMsg::WriteLine("Deleting " + Tools::ToString(recycledItems.size()) + " Scorpions");
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Scorpion* ScorpionObjectPool::GetScorpion()
{
	Scorpion* s;

	if (recycledItems.empty())
	{
		ConsoleMsg::WriteLine("New Scorpion"); // For illustration purposes

		s = new Scorpion();
	}
	else
	{
		ConsoleMsg::WriteLine("Recycled Scorpion"); // For illustration purposes

		s = recycledItems.top();
		recycledItems.pop();	// Remember: top doesn't pop and pop returns void...

		// Tell the object to register itself to the scene
		s->RegisterToCurrentScene();
	}

	return s;
}

void ScorpionObjectPool::ReturnScorpion(Scorpion* s)
{
	recycledItems.push(static_cast<Scorpion*>(s));

	// For illustration purposes
	ConsoleMsg::WriteLine("Recycled Stack Size, Scorpion: " + Tools::ToString(recycledItems.size()));
}