// CentipedeBodyFactory
// Katherine Burnett, October 2021

#ifndef _CentipedeBodyFactory
#define _CentipedeBodyFactory

#include "SFML/Graphics.hpp"
#include "CentipedeBodyObjectPool.h"
#include "MoveState.h"

class CentipedeBody;
class GameObject;
class CmdScore;
class CmdSound;

class CentipedeSpawner;

class CentipedeBodyFactory // singleton
{
private:
	static CentipedeBodyFactory* ptrInstance;

	CentipedeBodyFactory();
	CentipedeBodyFactory(const CentipedeBodyFactory&) = delete;
	CentipedeBodyFactory& operator=(const CentipedeBodyFactory&) = delete;
	~CentipedeBodyFactory() = default;

	static CentipedeBodyFactory& Instance(); // Access reference

	CentipedeBodyObjectPool myCentipedeBodyPool;
	CmdScore* pCmdScore;
	CmdSound* pCmdSoundKill;
	CentipedeSpawner* pCentipedeSpawner;

	std::vector<CentipedeBody*> ActiveCentipedeBodies;

	// Private NON_STATIC methods to perform actual work on member var
	CentipedeBody* privCreateCentipedeBody(int speed, int currentFrame, int row, int col, const MoveState* moveState);
	void privRecycleCentipedeBody(GameObject* cb);
	void privSetCentipedeSpawner(CentipedeSpawner* pCentipedeSpawner);
	void privFreezeAllCentipedeBodies();
	std::vector<CentipedeBody*> privGetActiveCentipedeBodies();
	void privDestroyAllActiveCentipedeBodies();
	void privSetCmdScore(CmdScore* pCmdScore);
	void privSetSoundCmds(CmdSound* pCmdSoundKill);

public:
	static void SetCmdScore(CmdScore* pCmdScore) { Instance().privSetCmdScore(pCmdScore); }
	static void SetSoundCmds(CmdSound* pCmdSoundKill) { Instance().privSetSoundCmds(pCmdSoundKill); }

	static CentipedeBody* CreateCentipedeBody(int speed, int currentFrame, int row, int col, const MoveState* moveState)
	{
		return Instance().privCreateCentipedeBody(speed, currentFrame, row, col, moveState);
	};

	static void RecycleCentipedeBody(GameObject* cb)
	{
		Instance().privRecycleCentipedeBody(cb);
	}

	static void SetCentipedeSpawner(CentipedeSpawner* pCentipedeSpawner)
	{
		Instance().privSetCentipedeSpawner(pCentipedeSpawner);
	}

	static void FreezeAllCentipedeBodies()
	{
		Instance().privFreezeAllCentipedeBodies();
	}

	std::vector<CentipedeBody*> GetActiveCentipedeBodies()
	{
		return Instance().privGetActiveCentipedeBodies();
	}

	static void DestroyAllActiveCentipedeBodies()
	{
		Instance().privDestroyAllActiveCentipedeBodies();
	}

	static void Terminate();
};


#endif _CentipedeHeadFactory