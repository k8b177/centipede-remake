#include "CmdSoundOnce.h"

#include "SoundManager.h"

CmdSoundOnce::CmdSoundOnce(sf::Sound s, SoundManager* pSM)
	:mySound(s), pSoundManager(pSM)
{
	mySound.setLoop(false);
}

void CmdSoundOnce::Execute()
{
	mySound.play();
}

void CmdSoundOnce::Stop()
{
	mySound.stop();
}

void CmdSoundOnce::SendToManager()
{
	pSoundManager->SendSoundCmd(this);
}