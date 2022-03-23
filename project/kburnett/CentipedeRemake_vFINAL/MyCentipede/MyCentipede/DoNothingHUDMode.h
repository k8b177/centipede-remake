// DoNothingHUDMode

#ifndef _DoNothingHUDMode
#define _DoNothingHUDMode

#include "PlayerHUDMode.h"

class DoNothingHUDMode : public PlayerHUDMode
{
public:
	DoNothingHUDMode() = default;
	DoNothingHUDMode(const DoNothingHUDMode&) = delete;
	DoNothingHUDMode& operator= (const DoNothingHUDMode&) = default;
	~DoNothingHUDMode() = default;

	void SetPlayerScore(HUDManager* pHM, int score) override
	{
		// do nothing
	};
	void SetPlayerLife(HUDManager* pHM, int lives) override
	{
		// do nothing
	};

};
#endif _P2HUDMode