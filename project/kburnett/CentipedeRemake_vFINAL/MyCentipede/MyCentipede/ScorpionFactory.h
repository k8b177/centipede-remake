// ScorpionFactory
// Katherine Burnett, October 2021

#ifndef _ScorpionFactory
#define _ScorpionFactory

#include "SFML/Graphics.hpp"
#include "ScorpionObjectPool.h"

#include <vector>

class GameObject;
class CmdScore;
class CmdSound;
class GridManager;
class ScorpionSpawner;

class ScorpionFactory // singleton
{
private:
	static ScorpionFactory* ptrInstance;

	ScorpionFactory();
	ScorpionFactory(const ScorpionFactory&) = delete;
	ScorpionFactory& operator=(const ScorpionFactory&) = delete;
	~ScorpionFactory() = default;

	static ScorpionFactory& Instance(); // Access reference

	ScorpionObjectPool myScorpionPool;
	CmdScore* pCmdScore;
	CmdSound* pCmdSoundCrawl;
	CmdSound* pCmdSoundKill;
	ScorpionSpawner* pScorpionSpawner;
	GridManager* pGridManager;

	std::vector<Scorpion*> ActiveScorpions;

	// Private NON_STATIC methods to perform actual work on member var
	void privCreateScorpion(sf::Vector2f pos, int speed, int row, int col, int direction);
	void privRecycleScorpion(GameObject* cb);
	void privSetGridManager(GridManager* pGridManager);
	void privSetScorpionSpawner(ScorpionSpawner* pScorpionSpawner);
	void privFreezeAllScorpions();
	std::vector<Scorpion*> privGetActiveScorpions();
	void privDestroyAllActiveScorpions();
	void privSetCmdScore(CmdScore* pCmdScore);
	void privSetSoundCmds(CmdSound* pCmdSoundCrawl, CmdSound* pCmdSoundKill);

public:
	static void CreateScorpion(sf::Vector2f pos, int speed, int row, int col, int direction)
	{
		Instance().privCreateScorpion(pos,speed,row,col,direction);
	};

	static void RecycleScorpion(GameObject* cb)
	{
		Instance().privRecycleScorpion(cb);
	}

	static void SetGridManager(GridManager* pGridManager) { Instance().privSetGridManager(pGridManager); }
	static void SetScorpionSpawner(ScorpionSpawner* pScorpionSpawner) { Instance().privSetScorpionSpawner(pScorpionSpawner); }
	static void SetCmdScore(CmdScore* pCmdScore) { Instance().privSetCmdScore(pCmdScore); }
	static void SetSoundCmds(CmdSound* pCmdSoundCrawl, CmdSound* pCmdSoundKill) { Instance().privSetSoundCmds(pCmdSoundCrawl, pCmdSoundKill); }

	static void FreezeAllScorpions()
	{
		Instance().privFreezeAllScorpions();
	}

	std::vector<Scorpion*> GetActiveScorpions()
	{
		return Instance().privGetActiveScorpions();
	}

	static void DestroyAllActiveScorpions()
	{
		Instance().privDestroyAllActiveScorpions();
	}

	static void Terminate();
};


#endif _ScorpionFactory