#include "CmdSoundLoop.h"

#include "SoundManager.h"

CmdSoundLoop::CmdSoundLoop(sf::Sound s, SoundManager* pSM)
	:mySound(s), pSoundManager(pSM)
{
	mySound.setLoop(true);
}

void CmdSoundLoop::Execute()
{
	mySound.play();
}

void CmdSoundLoop::Stop()
{
	mySound.stop();
}

void CmdSoundLoop::SendToManager()
{
	pSoundManager->SendSoundCmd(this);
}