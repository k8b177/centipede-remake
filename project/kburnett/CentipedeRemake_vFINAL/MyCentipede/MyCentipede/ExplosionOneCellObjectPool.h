// ExplosionOneCellObjectPool

#ifndef _ExplosionOneCellObjectPool
#define _ExplosionOneCellObjectPool

#include <stack>

class ExplosionOneCell;

class ExplosionOneCellObjectPool
{
private:
	std::stack<ExplosionOneCell*> recycledItems;

public:
	ExplosionOneCellObjectPool();
	ExplosionOneCellObjectPool(const ExplosionOneCellObjectPool&) = delete;
	ExplosionOneCellObjectPool& operator=(const ExplosionOneCellObjectPool&) = delete;
	~ExplosionOneCellObjectPool();

	ExplosionOneCell* GetExplosionOneCell();

	void ReturnExplosionOneCell(ExplosionOneCell* e);
};


#endif _ExplosionOneCellObjectPool
