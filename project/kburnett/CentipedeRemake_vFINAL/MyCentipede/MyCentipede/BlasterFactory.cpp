#include "BlasterFactory.h"

#include "Blaster.h"
#include "CmdSound.h"

BlasterFactory* BlasterFactory::ptrInstance = nullptr;

BlasterFactory::BlasterFactory()
	:blasterInstance(nullptr), pCmdSoundDeath(nullptr)
{

}

BlasterFactory& BlasterFactory::Instance()
{
	if (!ptrInstance)
		ptrInstance = new BlasterFactory();
	return *ptrInstance;
}

void BlasterFactory::privSetCmdSound(CmdSound* pCmdSoundDeath)
{
	this->pCmdSoundDeath = pCmdSoundDeath;
}

void BlasterFactory::privCreateBlaster()
{
	//Blaster* b = myBlasterPool.GetBlaster();
	blasterInstance = myBlasterPool.GetBlaster();

	// Declares that this object should be returned here (rather than deleted) when destroyed
	blasterInstance->SetExternalManagement(RecycleBlaster);

	blasterInstance->RegisterToCurrentScene();

	blasterInstance->Initialize(pCmdSoundDeath);
}

void BlasterFactory::privRecycleBlaster(GameObject* b)
{
	myBlasterPool.ReturnBlaster(static_cast<Blaster*>(b));
}

Blaster* BlasterFactory::privGetBlaster()
{
	return blasterInstance;
}

void BlasterFactory::Terminate()
{
	delete ptrInstance->pCmdSoundDeath;
	delete ptrInstance;
	ptrInstance = nullptr;
}
