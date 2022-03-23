// ExplosionTwoCell

#ifndef _ExplosionTwoCell
#define _ExplosionTwoCell

#include "Explosion.h"

class ExplosionTwoCell : public Explosion
{
public:
	// Big Four
	ExplosionTwoCell();
	ExplosionTwoCell(const ExplosionTwoCell&) = delete;
	ExplosionTwoCell& operator=(const ExplosionTwoCell&) = delete;
	~ExplosionTwoCell() = default;

};

#endif _ExplosionTwoCell
