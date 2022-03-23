// BulletFactory
// Katherine Burnett, October 2021

#ifndef _BulletFactory
#define _BulletFactory

#include "BulletObjectPool.h"

class GameObject;
class Blaster;
class CmdSound;

class BulletFactory // singleton
{
private:
	static BulletFactory* ptrInstance;

	BulletFactory() = default;
	BulletFactory(const BulletFactory&) = delete;
	BulletFactory& operator=(const BulletFactory&) = delete;
	~BulletFactory() = default;

	static BulletFactory& Instance(); // Access reference

	BulletObjectPool myBulletPool;
	Blaster* blaster;
	CmdSound* pCmdSound;

	// Private NON_STATIC methods to perform actual work on member var
	void privCreateBullet();
	void privRecycleBullet(GameObject* f);
	void privSetBlaster(Blaster* b);
	void privSetSoundCmd(CmdSound* c);

public:
	static void CreateBullet()
	{
		Instance().privCreateBullet();
	};

	static void RecycleBullet(GameObject* b)
	{
		Instance().privRecycleBullet(b);
	}

	static void SetBlaster(Blaster* b)
	{
		Instance().privSetBlaster(b);
	}

	static void SetSoundCmd(CmdSound* c)
	{
		Instance().privSetSoundCmd(c);
	}

	static void Terminate();
};


#endif _BulletFactory