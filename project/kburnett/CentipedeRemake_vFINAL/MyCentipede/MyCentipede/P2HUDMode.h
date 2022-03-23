// P2HUDMode

#ifndef _P2HUDMode
#define _P2HUDMode

#include "PlayerHUDMode.h"

class P2HUDMode : public PlayerHUDMode
{
public:
	P2HUDMode() = default;
	P2HUDMode(const P2HUDMode&) = delete;
	P2HUDMode& operator= (const P2HUDMode&) = default;
	~P2HUDMode() = default;

	void SetPlayerScore(HUDManager* pHM, int score) override;
	void SetPlayerLife(HUDManager* pHM, int lives) override;

};
#endif _P2HUDMode