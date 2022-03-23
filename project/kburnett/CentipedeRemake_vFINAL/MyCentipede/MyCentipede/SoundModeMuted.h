// SoundModeMuted - Concrete Strategy for SoundMode

#ifndef _SoundModeMuted
#define _SoundModeMuted

#include "SoundMode.h"

class SoundModeMuted : public SoundMode
{
public:
	// Big Four
	SoundModeMuted() = default;
	SoundModeMuted(const SoundModeMuted&) = delete;
	SoundModeMuted& operator=(const SoundModeMuted&) = delete;
	~SoundModeMuted() = default;

	void SoundUpdate(SoundManager* pSoundManager) override
	{
		// do nothing
	};
};

#endif _SoundModeMuted
