// BulletFactory
// Katherine Burnett, October 2022

#include "BulletFactory.h"
#include "Game Components/TEAL/CommonElements.h"
#include "BulletObjectPool.h"
#include "Bullet.h"
#include "CmdSound.h"
#include "Blaster.h"


BulletFactory* BulletFactory::ptrInstance = nullptr;


BulletFactory& BulletFactory::Instance()
{
	if (!ptrInstance)
		ptrInstance = new BulletFactory();
	return *ptrInstance;
}

void BulletFactory::privCreateBullet()
{
	pCmdSound->SendToManager(); // send BulletFire Sound command to Sound Manager

	Bullet* b = myBulletPool.GetBullet();

	// Declares that this object should be returned here (rather than deleted) when destroyed
	b->SetExternalManagement(RecycleBullet);

	b->Initialize(blaster);
}

void BulletFactory::privRecycleBullet(GameObject* b)
{
	myBulletPool.ReturnBullet(static_cast<Bullet*>(b));
}

void BulletFactory::privSetBlaster(Blaster* b)
{
	blaster = b;
}

void BulletFactory::privSetSoundCmd(CmdSound* c)
{
	this->pCmdSound = c;
}

void BulletFactory::Terminate()
{
	delete ptrInstance->pCmdSound;
	delete ptrInstance->blaster;
	delete ptrInstance;
	ptrInstance = nullptr;
}
