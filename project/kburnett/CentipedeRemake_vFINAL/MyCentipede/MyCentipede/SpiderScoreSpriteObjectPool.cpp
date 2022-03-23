#include "SpiderScoreSpriteObjectPool.h"

#include "SpiderScoreSprite.h"

SpiderScoreSpriteObjectPool::SpiderScoreSpriteObjectPool()
{

}

SpiderScoreSpriteObjectPool::~SpiderScoreSpriteObjectPool()
{
	// forcefully delete all recycled gameobjects
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

SpiderScoreSprite* SpiderScoreSpriteObjectPool::GetSpiderScoreSprite()
{
	SpiderScoreSprite* s;

	if (recycledItems.empty())
	{

		s = new SpiderScoreSprite();
	}
	else
	{

		s = recycledItems.top();
		recycledItems.pop();	// Remember: top doesn't pop and pop returns void...

		// Tell the object to register itself to the scene
		s->RegisterToCurrentScene();
	}

	return s;
}

void SpiderScoreSpriteObjectPool::ReturnSpiderScoreSprite(SpiderScoreSprite* s)
{
	recycledItems.push(static_cast<SpiderScoreSprite*>(s));

}