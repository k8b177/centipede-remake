#include "ExplosionTwoCellObjectPool.h"

#include "Game Components/TEAL/CommonElements.h"
#include "ExplosionTwoCell.h"

ExplosionTwoCellObjectPool::ExplosionTwoCellObjectPool()
{

}

ExplosionTwoCellObjectPool::~ExplosionTwoCellObjectPool()
{
	// forcefully delele all recycled gameobjects

	ConsoleMsg::WriteLine("Deleting " + Tools::ToString(recycledItems.size()) + " Explosions");
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

ExplosionTwoCell* ExplosionTwoCellObjectPool::GetExplosionTwoCell()
{
	ExplosionTwoCell* e;

	if (recycledItems.empty())
	{
		ConsoleMsg::WriteLine("New Explosion"); // For illustration purposes

		e = new ExplosionTwoCell();
	}
	else
	{
		ConsoleMsg::WriteLine("Recycled Explosion"); // For illustration purposes

		e = recycledItems.top();
		recycledItems.pop();	// Remember: top doesn't pop and pop returns void...

		// Tell the object to register itself to the scene
		e->RegisterToCurrentScene();
	}

	return e;
}

void ExplosionTwoCellObjectPool::ReturnExplosionTwoCell(ExplosionTwoCell* e)
{
	recycledItems.push(static_cast<ExplosionTwoCell*>(e));

	// For illustration purposes
	ConsoleMsg::WriteLine("Recycled Stack Size, Explosion: " + Tools::ToString(recycledItems.size()));
}