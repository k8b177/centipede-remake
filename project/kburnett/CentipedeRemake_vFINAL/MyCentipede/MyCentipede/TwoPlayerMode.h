// TwoPlayerMode - ConcreteStrategy for GameMode

#ifndef _TwoPlayerMode
#define _TwoPlayerMode

#include "GameMode.h"

class Player;

class TwoPlayerMode : public GameMode
{
public:
	// Big Four
	TwoPlayerMode() = default;
	TwoPlayerMode(const TwoPlayerMode&) = delete;
	TwoPlayerMode& operator=(const TwoPlayerMode&) = delete;
	~TwoPlayerMode() = default;

	void ModeSetup(PlayerManager* pPlayerManager, HUDManager* pHUDManager, SoundManager* pSoundManager, ScoreManager* pScoreManager) override;
	void ResetPlayerController(PlayerManager* pPlayerManager) override;
};

#endif _TwoPlayerMode