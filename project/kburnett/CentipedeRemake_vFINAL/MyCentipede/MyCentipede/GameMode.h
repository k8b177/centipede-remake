// GameMode - Strategy

#ifndef _GameMode
#define _GameMode

class PlayerManager;
class HUDManager;
class SoundManager;
class ScoreManager;

class GameMode
{
public:
	// Big Four
	GameMode() = default;
	GameMode(const GameMode&) = delete;
	GameMode& operator=(const GameMode&) = delete;
	~GameMode() = default;

	virtual void ModeSetup(PlayerManager* pPlayerManager, HUDManager* pHUDManager, SoundManager* pSoundManager, ScoreManager* pScoreManager) = 0;
	virtual void ResetPlayerController(PlayerManager* pPlayerManager) = 0;
};

#endif _GameMode
