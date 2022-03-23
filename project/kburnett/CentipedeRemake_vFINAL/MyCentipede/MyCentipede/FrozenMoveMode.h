// FrozenMoveMode - Concrete Strategy for CritterMoveMode

#ifndef _FrozenMoveMode
#define _FrozenMoveMode

#include "CritterMoveMode.h"

class FrozenMoveMode : public CritterMoveMode
{
public:
	// Big Four
	FrozenMoveMode() = default;
	FrozenMoveMode(const FrozenMoveMode&) = delete;
	FrozenMoveMode& operator=(const FrozenMoveMode&) = delete;
	~FrozenMoveMode() = default;

	void MoveUpdate(Critter* c) override { /* do Nothing, Critter is Frozen */ };
};

#endif _FrozenMoveMode
