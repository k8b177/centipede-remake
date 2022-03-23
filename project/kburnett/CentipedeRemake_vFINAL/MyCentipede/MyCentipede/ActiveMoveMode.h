// ActiveMoveMode - Concrete Strategy for CritterMoveMode

#ifndef _ActiveMoveMode
#define _ActiveMoveMode

#include "CritterMoveMode.h"

class ActiveMoveMode : public CritterMoveMode
{
public:
	// Big Four
	ActiveMoveMode() = default;
	ActiveMoveMode(const ActiveMoveMode&) = delete;
	ActiveMoveMode& operator=(const ActiveMoveMode&) = delete;
	~ActiveMoveMode() = default;

	void MoveUpdate(Critter* c) override;
};

#endif _ActiveMoveMode
