// BlasterObjectPool
// Katherine Burnett, October 2021

#ifndef _BlasterObjectPool
#define _BlasterObjectPool

#include <stack>
class Blaster;

class BlasterObjectPool
{
private:
	std::stack<Blaster*> recycledItems;

public:
	BlasterObjectPool() = default;
	BlasterObjectPool(const BlasterObjectPool&) = delete;
	BlasterObjectPool& operator=(const BlasterObjectPool&) = delete;
	~BlasterObjectPool();

	Blaster* GetBlaster();

	void ReturnBlaster(Blaster* b);
};


#endif _BulletObjectPool
