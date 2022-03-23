// FleaFactory
// Katherine Burnett, October 2021

#ifndef _FleaFactory
#define _FleaFactory

#include "SFML/Graphics.hpp"
#include "FleaObjectPool.h"

#include <vector>

class GameObject;
class CmdScore;
class CmdSound;
class GridManager;
class FleaSpawner;

class FleaFactory // singleton
{
private:
	static FleaFactory* ptrInstance;

	FleaFactory();
	FleaFactory(const FleaFactory&) = delete;
	FleaFactory& operator=(const FleaFactory&) = delete;
	~FleaFactory() = default;

	static FleaFactory& Instance(); // Access reference

	FleaObjectPool myFleaPool;
	float CurrentMushroomSpawnProbability;
	CmdScore* pCmdScore;
	CmdSound* pCmdSoundCrawl;
	CmdSound* pCmdSoundKill;
	GridManager* pGridManager;
	FleaSpawner* pFleaSpawner;

	std::vector<Flea*> ActiveFleas;


	// Private NON_STATIC methods to perform actual work on member var
	void privCreateFlea(sf::Vector2f pos, int col);
	void privRecycleFlea(GameObject* f);
	void privSetGridManager(GridManager* pGridManager);
	void privSetFleaSpawner(FleaSpawner* pFleaSpawner);
	void privFreezeAllFleas();
	std::vector<Flea*> privGetActiveFleas();
	void privDestroyAllActiveFleas();
	void privSetCmdScore(CmdScore* pCmdScore);
	void privSetSoundCmds(CmdSound* pCmdSoundCrawl, CmdSound* pCmdSoundKill);

public:
	static void CreateFlea(sf::Vector2f pos, int col)
	{
		Instance().privCreateFlea(pos, col);
	};

	static void RecycleFlea(GameObject* f)
	{
		Instance().privRecycleFlea(f);
	}
	
	static void SetCurrentMushroomSpawnProbability(float newRate)
	{
		Instance().CurrentMushroomSpawnProbability = newRate;
	}

	static void SetGridManager(GridManager* pGridManager)
	{
		Instance().privSetGridManager(pGridManager);
	}
	
	static void SetFleaSpawner(FleaSpawner* pFleaSpawner)
	{
		Instance().privSetFleaSpawner(pFleaSpawner);
	}

	static void SetCmdScore(CmdScore* pCmdScore) { Instance().privSetCmdScore(pCmdScore); }
	static void SetSoundCmds(CmdSound* pCmdSoundCrawl, CmdSound* pCmdSoundKill) { Instance().privSetSoundCmds(pCmdSoundCrawl, pCmdSoundKill); }

	static void FreezeAllFleas()
	{
		Instance().privFreezeAllFleas();
	}

	std::vector<Flea*> GetActiveFleas()
	{
		return Instance().privGetActiveFleas();
	}

	static void DestroyAllActiveFleas()
	{
		Instance().privDestroyAllActiveFleas();
	}

	static void Terminate();
};


#endif _FleaFactory