#include "ExplosionOneCellObjectPool.h"

#include "Game Components/TEAL/CommonElements.h"
#include "ExplosionOneCell.h"

ExplosionOneCellObjectPool::ExplosionOneCellObjectPool()
{

}

ExplosionOneCellObjectPool::~ExplosionOneCellObjectPool()
{
	// forcefully delele all recycled gameobjects

	ConsoleMsg::WriteLine("Deleting " + Tools::ToString(recycledItems.size()) + " Explosions");
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

ExplosionOneCell* ExplosionOneCellObjectPool::GetExplosionOneCell()
{
	ExplosionOneCell* e;

	if (recycledItems.empty())
	{
		ConsoleMsg::WriteLine("New Explosion"); // For illustration purposes

		e = new ExplosionOneCell();
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

void ExplosionOneCellObjectPool::ReturnExplosionOneCell(ExplosionOneCell* e)
{
	recycledItems.push(static_cast<ExplosionOneCell*>(e));

	// For illustration purposes
	ConsoleMsg::WriteLine("Recycled Stack Size, Explosion: " + Tools::ToString(recycledItems.size()));
}