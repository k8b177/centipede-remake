// OnePlayerMode - ConcreteStrategy for GameMode

#ifndef _OnePlayerMode
#define _OnePlayerMode

#include "GameMode.h"

class Player;

class OnePlayerMode : public GameMode
{
public:
	// Big Four
	OnePlayerMode() = default;
	OnePlayerMode(const OnePlayerMode&) = delete;
	OnePlayerMode& operator=(const OnePlayerMode&) = delete;
	~OnePlayerMode() = default;

	void ModeSetup(PlayerManager* pPlayerManager, HUDManager* pHUDManager, SoundManager* pSoundManager, ScoreManager* pScoreManager) override;
	void ResetPlayerController(PlayerManager* pPlayerManager) override;
};

#endif _OnePlayerMode
