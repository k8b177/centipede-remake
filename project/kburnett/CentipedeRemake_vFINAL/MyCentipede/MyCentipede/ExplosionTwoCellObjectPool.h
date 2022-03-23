// ExplosionTwoCellObjectPool

#ifndef _ExplosionTwoCellObjectPool
#define _ExplosionTwoCellObjectPool

#include <stack>

class ExplosionTwoCell;

class ExplosionTwoCellObjectPool
{
private:
	std::stack<ExplosionTwoCell*> recycledItems;

public:
	ExplosionTwoCellObjectPool();
	ExplosionTwoCellObjectPool(const ExplosionTwoCellObjectPool&) = delete;
	ExplosionTwoCellObjectPool& operator=(const ExplosionTwoCellObjectPool&) = delete;
	~ExplosionTwoCellObjectPool();

	ExplosionTwoCell* GetExplosionTwoCell();

	void ReturnExplosionTwoCell(ExplosionTwoCell* e);
};


#endif _ExplosionTwoCellObjectPool
