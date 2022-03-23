// CentipedeHeadFactory
// Katherine Burnett, October 2021

#ifndef _CentipedeHeadFactory
#define _CentipedeHeadFactory

#include "SFML/Graphics.hpp"
#include "CentipedeHeadObjectPool.h"
#include <vector>

class CentipedeHead;
class CentipedeSegment;
class GameObject;
class MoveState;
class CmdScore;
class CmdSound;

class CentipedeSpawner;

class CentipedeHeadFactory // singleton
{
private:
	static CentipedeHeadFactory* ptrInstance;

	CentipedeHeadFactory();
	CentipedeHeadFactory(const CentipedeHeadFactory&) = delete;
	CentipedeHeadFactory& operator=(const CentipedeHeadFactory&) = delete;
	~CentipedeHeadFactory() = default;

	static CentipedeHeadFactory& Instance(); // Access reference

	CentipedeHeadObjectPool myCentipedeHeadPool;
	CmdScore* pCmdScore;
	CmdSound* pCmdSoundCrawl;
	CmdSound* pCmdSoundKill;
	CentipedeSpawner* pCentipedeSpawner;

	std::vector<CentipedeHead*> ActiveCentipedeHeads;
	int ActiveHeadCount;

	// Private NON_STATIC methods to perform actual work on member var
	CentipedeHead* privCreateCentipedeHead(int speed, int currentFrame, int row, int col, CentipedeSegment* nextSegment, const MoveState* moveState);
	void privRecycleCentipedeHead(GameObject* ch);
	void privCheckCentipedeHeadCount();
	void privSetCentipedeSpawner(CentipedeSpawner* pCentipedeSpawner);
	void privFreezeAllCentipedeHeads();
	std::vector<CentipedeHead*> privGetActiveCentipedeHeads();
	void privDestroyAllActiveCentipedeHeads();
	void privSetCmdScore(CmdScore* pCmdScore);
	void privSetSoundCmds(CmdSound* pCmdSoundCrawl, CmdSound* pCmdSoundKill);

public:
	static void SetCmdScore(CmdScore* pCmdScore) { Instance().privSetCmdScore(pCmdScore); }
	static void SetSoundCmds(CmdSound* pCmdSoundCrawl, CmdSound* pCmdSoundKill) { Instance().privSetSoundCmds(pCmdSoundCrawl, pCmdSoundKill); }

	static CentipedeHead* CreateCentipedeHead(int speed, int currentFrame, int row, int col, CentipedeSegment* nextSegment, const MoveState* moveState)
	{
		return Instance().privCreateCentipedeHead(speed, currentFrame, row, col, nextSegment, moveState);
	};

	static void RecycleCentipedeHead(GameObject* ch)
	{
		Instance().privRecycleCentipedeHead(ch);
	}

	static void CheckCentipedeHeadCount()
	{
		Instance().privCheckCentipedeHeadCount();
	}

	static void SetCentipedeSpawner(CentipedeSpawner* pCentipedeSpawner)
	{
		Instance().privSetCentipedeSpawner(pCentipedeSpawner);
	}

	static void FreezeAllCentipedeHeads()
	{
		Instance().privFreezeAllCentipedeHeads();
	}

	std::vector<CentipedeHead*> GetActiveCentipedeHeads()
	{
		return Instance().privGetActiveCentipedeHeads();
	}

	static void DestroyAllActiveCentipedeHeads()
	{
		Instance().privDestroyAllActiveCentipedeHeads();
	}

	static void Terminate();
};


#endif _CentipedeHeadFactory