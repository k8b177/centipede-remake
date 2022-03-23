// CritterSpawner
// Katherine Burnett, September 2021

#ifndef _CritterSpawner
#define _CritterSpawner

#include "Game Components/TEAL/CommonElements.h"

enum class Active {
	On,
	Off
};

class CritterSpawner : GameObject
{
public:
	CritterSpawner();
	CritterSpawner(const CritterSpawner&) = delete;
	CritterSpawner& operator= (const CritterSpawner&) = delete;
	~CritterSpawner() = default;
};

#endif _CritterSpawner