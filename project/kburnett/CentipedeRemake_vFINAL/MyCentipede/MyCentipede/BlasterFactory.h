// BlasterFactory

#ifndef _BlasterFactory
#define _BlasterFactory

#include "SFML/Graphics.hpp"
#include "GameConstants.h"
#include "BlasterObjectPool.h"

class GameObject;
class Blaster;
class CmdSound;

class BlasterFactory // singleton
{
private:
	static BlasterFactory* ptrInstance;

	BlasterFactory();
	BlasterFactory(const BlasterFactory&) = delete;
	BlasterFactory& operator=(const BlasterFactory&) = delete;
	~BlasterFactory() = default;

	static BlasterFactory& Instance(); // Access reference


	// Private NON_STATIC methods to perform actual work on member var
	void privSetCmdSound(CmdSound* pCmdSoundDeath);
	void privCreateBlaster();
	void privRecycleBlaster(GameObject* b);
	Blaster* privGetBlaster();
	

	// Private member vars
	Blaster* blasterInstance;

	BlasterObjectPool myBlasterPool;
	CmdSound* pCmdSoundDeath;

public:
	static void SetCmdSound(CmdSound* pCmdSoundDeath)
	{
		Instance().privSetCmdSound(pCmdSoundDeath);
	}
	static void CreateBlaster()
	{
		Instance().privCreateBlaster();
	};

	static void RecycleBlaster(GameObject* b)
	{
		Instance().privRecycleBlaster(b);
	}


	static Blaster* GetBlaster()
	{
		return Instance().privGetBlaster();
	}

	static void Terminate();
};


#endif _BlasterFactory