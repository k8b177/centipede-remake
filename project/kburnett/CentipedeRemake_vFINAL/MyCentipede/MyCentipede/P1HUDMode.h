// P1HUDMode

#ifndef _P1HUDMode
#define _P1HUDMode

#include "PlayerHUDMode.h"

class P1HUDMode : public PlayerHUDMode
{
public:
	P1HUDMode() = default;
	P1HUDMode(const P1HUDMode&) = delete;
	P1HUDMode& operator= (const P1HUDMode&) = default;
	~P1HUDMode() = default;

	void SetPlayerScore(HUDManager* pHM, int score) override;
	void SetPlayerLife(HUDManager* pHM, int lives) override;

};
#endif _P2HUDMode