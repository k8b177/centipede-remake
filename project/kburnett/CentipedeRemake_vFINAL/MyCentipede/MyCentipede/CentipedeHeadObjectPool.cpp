#include "CentipedeHeadObjectPool.h"
#include "Game Components/TEAL/CommonElements.h"
#include "CentipedeHead.h"

CentipedeHeadObjectPool::CentipedeHeadObjectPool()
{
	
}

CentipedeHeadObjectPool::~CentipedeHeadObjectPool()
{
	// forcefully delele all recycled gameobjects

	ConsoleMsg::WriteLine("Deleting " + Tools::ToString(recycledItems.size()) + " CentipedeHeads");
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

CentipedeHead* CentipedeHeadObjectPool::GetCentipedeHead()
{
	CentipedeHead* ch;

	if (recycledItems.empty())
	{
		ConsoleMsg::WriteLine("New CentipedeHead"); // For illustration purposes

		ch = new CentipedeHead();
	}
	else
	{
		ConsoleMsg::WriteLine("Recycled CentipedeHead"); // For illustration purposes

		ch = recycledItems.top();
		recycledItems.pop();	// Remember: top doesn't pop and pop returns void...

		// Tell the object to register itself to the scene
		ch->RegisterToCurrentScene();
	}

	return ch;
}

void CentipedeHeadObjectPool::ReturnCentipedeHead(CentipedeHead* ch)
{
	recycledItems.push(static_cast<CentipedeHead*>(ch));

	// For illustration purposes
	ConsoleMsg::WriteLine("Recycled Stack Size, CentipedeHead: " + Tools::ToString(recycledItems.size()));

}