#include "BlasterObjectPool.h"
#include "Game Components/TEAL/CommonElements.h"
#include "Blaster.h"

BlasterObjectPool::~BlasterObjectPool()
{
	// forcefully delele all recycled gameobjects
	while (!recycledItems.empty())
	{
		// delete recycledItems.top();
		recycledItems.pop();
	}
}

Blaster* BlasterObjectPool::GetBlaster()
{
	Blaster* b;

	if (recycledItems.empty())
	{
		b = new Blaster();
	}
	else
	{
		b = recycledItems.top();
		recycledItems.pop();

		b->RegisterToCurrentScene();
	}

	return b;
}

void BlasterObjectPool::ReturnBlaster(Blaster* b)
{
	recycledItems.push(static_cast<Blaster*>(b));
}