#include "SpiderObjectPool.h"
#include "Game Components/TEAL/CommonElements.h"
#include "Spider.h"

SpiderObjectPool::SpiderObjectPool()
{

}

SpiderObjectPool::~SpiderObjectPool()
{
	// forcefully delele all recycled gameobjects

	ConsoleMsg::WriteLine("Deleting " + Tools::ToString(recycledItems.size()) + " Spiders");
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Spider* SpiderObjectPool::GetSpider()
{
	Spider* s;

	if (recycledItems.empty())
	{
		ConsoleMsg::WriteLine("New Spider"); // For illustration purposes

		s = new Spider();
	}
	else
	{
		ConsoleMsg::WriteLine("Recycled Spider"); // For illustration purposes

		s = recycledItems.top();
		recycledItems.pop();	// Remember: top doesn't pop and pop returns void...

		// Tell the object to register itself to the scene
		s->RegisterToCurrentScene();
	}

	return s;
}

void SpiderObjectPool::ReturnSpider(Spider* s)
{
	recycledItems.push(static_cast<Spider*>(s));

	// For illustration purposes
	ConsoleMsg::WriteLine("Recycled Stack Size, Spider: " + Tools::ToString(recycledItems.size()));
}