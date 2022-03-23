#include "SoundManager.h"

#include "CmdSoundOnce.h"
#include "CmdSoundLoop.h"


#include "ScorpionFactory.h"
#include "CentipedeHeadFactory.h"
#include "CentipedeBodyFactory.h"
#include "FleaFactory.h"
#include "SpiderFactory.h"
#include "MushroomFactory.h"
#include "BlasterFactory.h"
#include "BulletFactory.h"

#include "SoundModeOn.h"
#include "SoundModeMuted.h"

SoundManager::SoundManager()
	:CurrentSoundMode(nullptr), pSoundModeMuted(nullptr), pSoundModeOn(nullptr)
{

}

void SoundManager::Initialize()
{
	// Assign Sounds from Resource Manager & set volume on all of them
	BulletFireSnd.setBuffer(ResourceManager::GetSound("BulletFire"));
	BulletFireSnd.setVolume(GameConstants::VOLUME);
	ScorpionSnd.setBuffer(ResourceManager::GetSound("Scorpion"));
	ScorpionSnd.setVolume(GameConstants::VOLUME);
	CentipedeFootstep.setBuffer(ResourceManager::GetSound("CentipedeFootstep"));
	CentipedeFootstep.setVolume(GameConstants::VOLUME);
	SpiderSnd.setBuffer(ResourceManager::GetSound("Spider"));
	SpiderSnd.setVolume(GameConstants::VOLUME);
	CritterKill.setBuffer(ResourceManager::GetSound("CritterKill"));
	CritterKill.setVolume(GameConstants::VOLUME);
	FleaSpawn.setBuffer(ResourceManager::GetSound("FleaSpawn"));
	FleaSpawn.setVolume(GameConstants::VOLUME);
	PlayerDeath.setBuffer(ResourceManager::GetSound("PlayerDeath"));
	PlayerDeath.setVolume(GameConstants::VOLUME);
	MushroomRegen.setBuffer(ResourceManager::GetSound("MushroomRegen"));
	MushroomRegen.setVolume(GameConstants::VOLUME);
	ExtraLifeSnd.setBuffer(ResourceManager::GetSound("ExtraLife"));
	ExtraLifeSnd.setVolume(GameConstants::VOLUME);

	// Set Sound Commands in Factories

	// Sending Sound Commands to Bullet Factory, Blaster Factory, and Mushroom Factory
	BulletFactory::SetSoundCmd(GetSoundCommand(SoundEvents::BulletFireSnd));
	BlasterFactory::SetCmdSound(GetSoundCommand(SoundEvents::PlayerDeathSnd));
	MushroomFactory::SetCmdSound(GetSoundCommand(SoundEvents::MushroomRegen));

	// Creating one instance of the CritterKill sound to pass to all the critter factories
	CmdSound* pCritterKillSnd = GetSoundCommand(SoundEvents::CritterKill);

	// Sending Sound Commands to all Critter Factories
	ScorpionFactory::SetSoundCmds(GetSoundCommand(SoundEvents::ScorpionSnd), pCritterKillSnd);
	CentipedeHeadFactory::SetSoundCmds(GetSoundCommand(SoundEvents::CentipedeFootstep), pCritterKillSnd);
	CentipedeBodyFactory::SetSoundCmds(pCritterKillSnd);
	SpiderFactory::SetSoundCmds(GetSoundCommand(SoundEvents::SpiderSnd), pCritterKillSnd);
	FleaFactory::SetSoundCmds(GetSoundCommand(SoundEvents::FleaSnd), pCritterKillSnd);

	pSoundModeOn = new SoundModeOn();
	pSoundModeMuted = new SoundModeMuted();

	CurrentSoundMode = pSoundModeMuted;
}

CmdSound* SoundManager::GetSoundCommand(SoundEvents ev)
{
	CmdSound* pCmd = nullptr;

	switch (ev)
	{
	case SoundEvents::BulletFireSnd:
		pCmd = new CmdSoundOnce(BulletFireSnd, this);
		break;
	case SoundEvents::ScorpionSnd:
		pCmd = new CmdSoundLoop(ScorpionSnd, this);
		break;
	case SoundEvents::CentipedeFootstep:
		pCmd = new CmdSoundLoop(CentipedeFootstep, this);
		break;
	case SoundEvents::SpiderSnd:
		pCmd = new CmdSoundLoop(SpiderSnd, this);
		break;
	case SoundEvents::CritterKill:
		pCmd = new CmdSoundOnce(CritterKill, this);
		break;
	case SoundEvents::FleaSnd:
		pCmd = new CmdSoundOnce(FleaSpawn, this);
		break;
	case SoundEvents::PlayerDeathSnd:
		pCmd = new CmdSoundOnce(PlayerDeath, this);
		break;
	case SoundEvents::MushroomRegen:
		pCmd = new CmdSoundOnce(MushroomRegen, this);
		break;
	case SoundEvents::ExtraLife:
		pCmd = new CmdSoundOnce(ExtraLifeSnd, this);
		break;
	default:
		break;
	}

	return pCmd;
}


void SoundManager::SendSoundCmd(CmdSound* c)
{
	QueueCmds.push(c);
}

void SoundManager::ClearQueue()
{
	while (!QueueCmds.empty())
	{
		QueueCmds.pop();
	}
}

void SoundManager::ProcessSounds()
{
	CmdSound* c;

	while (!QueueCmds.empty())
	{
		c = QueueCmds.front();
		c->Execute();

		QueueCmds.pop();
	}
}

void SoundManager::SetOn()
{
	CurrentSoundMode = pSoundModeOn;
}
void SoundManager::SetMuted()
{
	CurrentSoundMode = pSoundModeMuted;
}

void SoundManager::SoundUpdate()
{
	CurrentSoundMode->SoundUpdate(this);
}

SoundManager::~SoundManager()
{
	delete pSoundModeOn;
	delete pSoundModeMuted;
}
