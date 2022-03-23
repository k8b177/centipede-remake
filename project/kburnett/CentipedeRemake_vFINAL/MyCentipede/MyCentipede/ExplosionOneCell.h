// ExplosionOneCell

#ifndef _ExplosionOneCell
#define _ExplosionOneCell

#include "Explosion.h"

class ExplosionOneCell : public Explosion
{
public:
	// Big Four
	ExplosionOneCell();
	ExplosionOneCell(const ExplosionOneCell&) = delete;
	ExplosionOneCell& operator=(const ExplosionOneCell&) = delete;
	~ExplosionOneCell() = default;

};

#endif _ExplosionOneCell
