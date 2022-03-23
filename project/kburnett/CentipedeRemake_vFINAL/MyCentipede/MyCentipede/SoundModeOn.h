// SoundModeOn - Concrete Strategy for SoundMode

#ifndef _SoundModeOn
#define _SoundModeOn

#include "SoundMode.h"

class SoundModeOn : public SoundMode
{
public:
	// Big Four
	SoundModeOn() = default;
	SoundModeOn(const SoundModeOn&) = delete;
	SoundModeOn& operator=(const SoundModeOn&) = delete;
	~SoundModeOn() = default;

	void SoundUpdate(SoundManager* pSoundManager) override;
};

#endif _SoundMode
