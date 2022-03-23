// SpiderObjectPool
// Katherine Burnett, October 2021

#ifndef _SpiderObjectPool
#define _SpiderObjectPool

#include <stack>
class Spider;

class SpiderObjectPool
{
private:
	std::stack<Spider*> recycledItems;

public:
	SpiderObjectPool();
	SpiderObjectPool(const SpiderObjectPool&) = delete;
	SpiderObjectPool& operator=(const SpiderObjectPool&) = delete;
	~SpiderObjectPool();

	Spider* GetSpider();

	void ReturnSpider(Spider* s);
};


#endif _SpiderObjectPool
