#include "CentipedeBodyObjectPool.h"
#include "Game Components/TEAL/CommonElements.h"
#include "CentipedeBody.h"

CentipedeBodyObjectPool::CentipedeBodyObjectPool()
{

}

CentipedeBodyObjectPool::~CentipedeBodyObjectPool()
{
	// forcefully delele all recycled gameobjects

	ConsoleMsg::WriteLine("Deleting " + Tools::ToString(recycledItems.size()) + " CentipedeBodies");
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

CentipedeBody* CentipedeBodyObjectPool::GetCentipedeBody()
{
	CentipedeBody* cb;

	if (recycledItems.empty())
	{
		ConsoleMsg::WriteLine("New CentipedeBody"); // For illustration purposes

		cb = new CentipedeBody();
	}
	else
	{
		ConsoleMsg::WriteLine("Recycled CentipedeBody"); // For illustration purposes

		cb = recycledItems.top();
		recycledItems.pop();	// Remember: top doesn't pop and pop returns void...

		// Tell the object to register itself to the scene
		cb->RegisterToCurrentScene();
	}

	return cb;
}

void CentipedeBodyObjectPool::ReturnCentipedeBody(CentipedeBody* cb)
{
	recycledItems.push(static_cast<CentipedeBody*>(cb));

	// For illustration purposes
	ConsoleMsg::WriteLine("Recycled Stack Size, CentipedeBody: " + Tools::ToString(recycledItems.size()));

}