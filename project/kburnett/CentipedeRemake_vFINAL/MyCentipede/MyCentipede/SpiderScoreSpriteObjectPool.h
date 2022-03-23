// SpiderScoreSpriteObjectPool

#ifndef _SpiderScoreSpriteObjectPool
#define _SpiderScoreSpriteObjectPool

#include <stack>

class SpiderScoreSprite;

class SpiderScoreSpriteObjectPool
{
private:
	std::stack<SpiderScoreSprite*> recycledItems;

public:
	SpiderScoreSpriteObjectPool();
	SpiderScoreSpriteObjectPool(const SpiderScoreSpriteObjectPool&) = delete;
	SpiderScoreSpriteObjectPool& operator=(const SpiderScoreSpriteObjectPool&) = delete;
	~SpiderScoreSpriteObjectPool();

	SpiderScoreSprite* GetSpiderScoreSprite();

	void ReturnSpiderScoreSprite(SpiderScoreSprite* m);
};


#endif _SpiderScoreSpriteObjectPool
