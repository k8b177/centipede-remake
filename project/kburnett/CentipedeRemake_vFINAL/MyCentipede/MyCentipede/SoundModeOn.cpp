#include "SoundModeOn.h"

#include "SoundManager.h"

void SoundModeOn::SoundUpdate(SoundManager* pSoundManager)
{
	pSoundManager->ProcessSounds();
}