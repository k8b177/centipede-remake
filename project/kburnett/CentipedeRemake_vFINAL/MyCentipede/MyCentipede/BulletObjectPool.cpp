#include "BulletObjectPool.h"
#include "Game Components/TEAL/CommonElements.h"
#include "Bullet.h"

BulletObjectPool::~BulletObjectPool()
{
	// forcefully delele all recycled gameobjects
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Bullet* BulletObjectPool::GetBullet()
{
	Bullet* b;

	if (recycledItems.empty())
	{
		b = new Bullet();
	}
	else
	{
		b = recycledItems.top();
		recycledItems.pop();

		b->RegisterToCurrentScene();
	}

	return b;
}

void BulletObjectPool::ReturnBullet(Bullet* b)
{
	recycledItems.push(static_cast<Bullet*>(b));
}