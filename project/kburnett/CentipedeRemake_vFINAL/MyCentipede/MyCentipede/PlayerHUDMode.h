// PlayerHUDMode

#ifndef _PlayerHUDMode
#define _PlayerHUDMode

class HUDManager;

class PlayerHUDMode
{
public:
	PlayerHUDMode() = default;
	PlayerHUDMode(const PlayerHUDMode&) = delete;
	PlayerHUDMode& operator= (const PlayerHUDMode&) = default;
	~PlayerHUDMode() = default;

	virtual void SetPlayerScore(HUDManager* pHM, int score) = 0;
	virtual void SetPlayerLife(HUDManager* pHM, int lives) = 0;

};
#endif _PlayerHUDMode