// CmdSound

#ifndef _CmdSound
#define _CmdSound

#include "Game Components/TEAL/ResourceManager.h"

class SoundManager;

class CmdSound
{
public:
	// Big Four
	CmdSound() = default;
	CmdSound(const CmdSound&) = delete;
	CmdSound& operator= (const CmdSound&) = delete;
	~CmdSound() { };

	// Note: the Excecute method must NOT have _any_ paramters
	virtual void Execute() = 0;
	virtual void Stop() = 0;
	virtual void SendToManager() = 0;

};

#endif _CmdSound
