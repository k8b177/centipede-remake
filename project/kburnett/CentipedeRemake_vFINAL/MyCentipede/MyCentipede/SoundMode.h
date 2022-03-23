// SoundMode - Strategy

#ifndef _SoundMode
#define _SoundMode

class SoundManager;

class SoundMode
{
public:
	// Big Four
	SoundMode() = default;
	SoundMode(const SoundMode&) = delete;
	SoundMode& operator=(const SoundMode&) = delete;
	~SoundMode() = default;

	virtual void SoundUpdate(SoundManager* pSoundManager) = 0;
};

#endif _SoundMode
