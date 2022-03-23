// GameEntityManager

#ifndef _GameEntityManager
#define _GameEntityManager

class GridManager;
class PlayerManager;
struct WaveData;

class BlasterSpawner;
class ScorpionSpawner;
class SpiderSpawner;
class FleaSpawner;
class CentipedeSpawner;

class ActiveMoveMode;
class FrozenMoveMode;

class Player;

class GameEntityManager
{
public:
	// Big Four
	GameEntityManager();
	GameEntityManager(const GameEntityManager&) = delete;
	GameEntityManager& operator=(const GameEntityManager&) = delete;
	~GameEntityManager();

	// Methods
	void CreateEntities();
	void FillField(Player* p);
	GridManager* GridManagerAccessor();
	void SendOutWaveDataToSpawners(WaveData data);
	void CancelSpawnerAlarms();
	void SpawnBlaster();
	void FreezeAllEntities();
	void DestroyAllActiveCritters();
	void ResetBlasterPos();

private:
	// Private member vars
	GridManager* myGridManager;
	PlayerManager* pPlayerManager;

	BlasterSpawner* myBlasterSpawner;
	ScorpionSpawner* myScorpionSpawner;
	SpiderSpawner* mySpiderSpawner;
	FleaSpawner* myFleaSpawner;
	CentipedeSpawner* myCentipedeSpawner;

	ActiveMoveMode* pActiveMoveMode;
	FrozenMoveMode* pFrozenMoveMode;
};

#endif _GameEntityManager
