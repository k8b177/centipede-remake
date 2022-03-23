// SoundManager

#ifndef _SoundManager
#define _SoundManager

#include <queue>
#include "SoundEventsEnum.h"

#include "Game Components/TEAL/CommonElements.h"

class CmdSound;

class SoundMode;
class SoundModeOn;
class SoundModeMuted;

class SoundManager
{
public:
	// Big Four
	SoundManager();
	SoundManager(const SoundManager&) = default;
	SoundManager& operator= (const SoundManager&) = default;
	~SoundManager();

	void Initialize();

	void SendSoundCmd(CmdSound* c);
	void ProcessSounds();
	void ClearQueue();

	void SetOn();
	void SetMuted();

	void SoundUpdate();

	CmdSound* GetSoundCommand(SoundEvents ev);

private:
	// Sounds
	sf::Sound BulletFireSnd;
	sf::Sound ScorpionSnd;
	sf::Sound CentipedeFootstep;
	sf::Sound SpiderSnd;
	sf::Sound CritterKill;
	sf::Sound FleaSpawn;
	sf::Sound PlayerDeath;
	sf::Sound MushroomRegen;
	sf::Sound ExtraLifeSnd;


	// solo instances of concrete strategy patterns for SoundMode
	SoundModeOn* pSoundModeOn;
	SoundModeMuted* pSoundModeMuted;
	SoundMode* CurrentSoundMode;

	std::queue<CmdSound*> QueueCmds;

};

#endif _SoundManager