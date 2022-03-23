// CmdSoundOnce

#ifndef _CmdSoundOnce
#define _CmdSoundOnce

#include "CmdSound.h"

class CmdSoundOnce : public CmdSound
{
public:
	// Big Four
	CmdSoundOnce() = default;
	CmdSoundOnce(const CmdSoundOnce&) = delete;
	CmdSoundOnce& operator= (const CmdSoundOnce&) = delete;
	~CmdSoundOnce() = default;

	CmdSoundOnce(sf::Sound s, SoundManager* pSM);

	void Execute();
	void Stop();
	void SendToManager();

private:
	sf::Sound mySound;
	SoundManager* pSoundManager;
};

#endif _CmdSoundOnce