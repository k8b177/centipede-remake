// CritterMoveMode - Strategy Base 

#ifndef _CritterMoveMode
#define _CritterMoveMode

class Critter;

class CritterMoveMode 
{
public:
	// Big Four
	CritterMoveMode() = default;
	CritterMoveMode(const CritterMoveMode&) = delete;
	CritterMoveMode& operator=(const CritterMoveMode&) = delete;
	~CritterMoveMode() = default;

	virtual void MoveUpdate(Critter* c) = 0;
};

#endif _FrozenMoveMode
