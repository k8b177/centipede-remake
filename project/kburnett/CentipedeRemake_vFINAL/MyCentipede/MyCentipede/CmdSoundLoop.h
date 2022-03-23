// CmdSoundLoop

#ifndef _CmdSoundLoop
#define _CmdSoundLoop

#include "CmdSound.h"

class CmdSoundLoop : public CmdSound
{
public:
	// Big Four
	CmdSoundLoop() = default;
	CmdSoundLoop(const CmdSoundLoop&) = delete;
	CmdSoundLoop& operator= (const CmdSoundLoop&) = delete;
	~CmdSoundLoop() = default;

	CmdSoundLoop(sf::Sound s, SoundManager* pSM);

	void Execute();
	void Stop();
	void SendToManager();

private:
	sf::Sound mySound;
	SoundManager* pSoundManager;
};

#endif _CmdSoundLoop