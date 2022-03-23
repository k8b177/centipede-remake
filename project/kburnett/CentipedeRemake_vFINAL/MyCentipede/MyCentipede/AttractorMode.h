// AttractorMode - ConcreteStrategy for GameMode

#ifndef _AttractorMode
#define _AttractorMode

#include "GameMode.h"


class AttractorMode : public GameMode
{
public:
	// Big Four
	AttractorMode() = default;
	AttractorMode(const AttractorMode&) = delete;
	AttractorMode& operator=(const AttractorMode&) = delete;
	~AttractorMode() = default;

	void ModeSetup(PlayerManager* pPlayerManager, HUDManager* pHUDManager, SoundManager* pSoundManager, ScoreManager* pScoreManager) override;
	void ResetPlayerController(PlayerManager* pPlayerManager) override;

private:

};

#endif _AttractorMode