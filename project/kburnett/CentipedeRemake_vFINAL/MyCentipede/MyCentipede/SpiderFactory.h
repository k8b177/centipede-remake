// ScorpionFactory
// Katherine Burnett, October 2021

#ifndef _SpiderFactory
#define _SpiderFactory

#include "SFML/Graphics.hpp"
#include "SpiderObjectPool.h"

#include <vector>

class GameObject;
class CmdScore;
class CmdSound;
class GridManager;
class SpiderSpawner;


class SpiderFactory // singleton
{
private:
	static SpiderFactory* ptrInstance;

	SpiderFactory();
	SpiderFactory(const SpiderFactory&) = delete;
	SpiderFactory& operator=(const SpiderFactory&) = delete;
	~SpiderFactory() = default;

	static SpiderFactory& Instance(); // Access reference

	SpiderObjectPool mySpiderObjectPool;
	CmdScore* pCmdScore;
	CmdSound* pCmdSoundCrawl;
	CmdSound* pCmdSoundKill;
	GridManager* pGridManager;
	SpiderSpawner* pSpiderSpawner;

	std::vector<Spider*> ActiveSpiders; // stack of ActiveSpiders

	// Private NON_STATIC methods to perform actual work on member var
	void privCreateSpider(sf::Vector2f pos, int speed, int row, int col, int direction);
	void privRecycleSpider(GameObject* cb);
	void privSetSpiderSpawner(SpiderSpawner* pSpiderSpawner);
	void privSetGridManager(GridManager* pGridManager);
	void privFreezeAllSpiders();
	std::vector<Spider*> privGetActiveSpiders();
	void privDestroyAllActiveSpiders();
	void privSetCmdScore(CmdScore* pCmdScore);
	void privSetSoundCmds(CmdSound* pCmdSoundCrawl, CmdSound* pCmdSoundKill);

public:
	static void CreateSpider(sf::Vector2f pos, int speed, int row, int col, int direction)
	{
		Instance().privCreateSpider(pos, speed, row, col, direction);
	};

	static void RecycleSpider(GameObject* cb)
	{
		Instance().privRecycleSpider(cb);
	}

	static void SetSpiderSpawner(SpiderSpawner* pSpiderSpawner) { Instance().privSetSpiderSpawner(pSpiderSpawner); }
	static void SetGridManager(GridManager* pGridManager) { Instance().privSetGridManager(pGridManager); }
	static void SetCmdScore(CmdScore* pCmdScore) { Instance().privSetCmdScore(pCmdScore); }
	static void SetSoundCmds(CmdSound* pCmdSoundCrawl, CmdSound* pCmdSoundKill) { Instance().privSetSoundCmds(pCmdSoundCrawl, pCmdSoundKill); }

	static void FreezeAllSpiders()
	{
		Instance().privFreezeAllSpiders();
	}

	std::vector<Spider*> GetActiveSpiders()
	{
		return Instance().privGetActiveSpiders();
	}

	static void DestroyAllActiveSpiders()
	{
		Instance().privDestroyAllActiveSpiders();
	}
	

	static void Terminate();
};


#endif _SpiderFactory