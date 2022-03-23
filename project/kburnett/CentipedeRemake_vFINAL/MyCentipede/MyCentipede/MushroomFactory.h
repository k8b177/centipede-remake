// MushroomFactory
// Katherine Burnett, October 2021

#ifndef _MushroomFactory
#define _MushroomFactory

#include "SFML/Graphics.hpp"
#include "MushroomObjectPool.h"


class GameObject;
class CmdScore;
class CmdSound;
class GridManager;

class MushroomFactory  // singleton
{
private:
	static MushroomFactory* ptrInstance;

	MushroomFactory();
	MushroomFactory(const MushroomFactory&) = delete;
	MushroomFactory& operator=(const MushroomFactory&) = delete;
	~MushroomFactory() = default;

	static MushroomFactory& Instance(); // Access reference

	MushroomObjectPool myMushroomPool;
	CmdScore* pPoisonShroomDeath;
	CmdScore* pRegularShroomDeath;
	CmdScore* pRegenPoints;
	CmdSound* pRegenSnd;
	GridManager* pGridManager;

	// Private NON_STATIC methods to perform actual work on member var
	void privCreateMushroom(int row, int col);
	void privRecycleMushroom(GameObject* m);
	void privSetPGridManager(GridManager* p);
	void privSetCmdScores(CmdScore* pCmdScorePoison, CmdScore* pCmdScoreRegular, CmdScore* pCmdScoreRegen);
	void privSetGridManager(GridManager* pGridManager);
	void privSetCmdSound(CmdSound* pRegenSnd);

public:
	static void SetCmdScores(CmdScore* pCmdScorePoison, CmdScore* pCmdScoreRegular, CmdScore* pCmdScoreRegen) { Instance().privSetCmdScores(pCmdScorePoison, pCmdScoreRegular, pCmdScoreRegen); }
	static void SetCmdSound(CmdSound* pRegenSnd) { Instance().privSetCmdSound(pRegenSnd); }
	static void SetGridManager(GridManager* pGridManager) { Instance().privSetGridManager(pGridManager); }

	static void CreateMushroom(int row, int col)
	{
		Instance().privCreateMushroom(row, col);
	};

	static void RecycleMushroom(GameObject* m)
	{
		Instance().privRecycleMushroom(m);
	}

	static void Terminate();
};


#endif _CentipedeHeadFactory