// GameManager
// Katherine Burnett, September 2021

#ifndef _GameManager
#define _GameManager

#include "Game Components/TEAL/CommonElements.h"

#include "GameModeEnum.h"
#include "WaveData.h"

class GameMode;
class OnePlayerMode;
class TwoPlayerMode;
class AttractorMode;

class StartGameChecker;
class StartGameCheckerOn;
class StartGameCheckerOff;

class GameEntityManager;
class PlayerManager;
class GridManager;
class WaveManager;
class HUDManager;
class ScoreManager;
class SoundManager;


class GameManager : GameObject // singleton
{
private:
	static GameManager* ptrInstance;

	static GameManager& Instance();

	// ----- BIG FOUR ----- //
	GameManager() = default;
	GameManager(const GameManager&) = default;
	GameManager& operator= (const GameManager&) = default;
	~GameManager() = default;


	// ----- PRIVATE METHODS ----- //

	// GameObject Methods
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	// Methods for game flow, can be called externally
	void privGameInitialize();
	void privSetGameMode(GameModeEnum newGameMode);
	void privEndOfWaveCallback();
	void privEndOfMushroomRegen();
	void privLossOfLifeCallback();
	void privTurnStartGameCheckerOn();
	void privTurnStartGameCheckerOff();

	// internal methods
	WaveData GetWaveData(int wave_number);
	void SendOutWaveDataToSpawners(WaveData waveData);
	void StartWave(int wave_number);
	void Start();
	void End();

	// Accessors
	GridManager* privGridManagerAccessor();
	PlayerManager* privPlayerManagerAccessor();


	// ----- PRIVATE MEMBER VARS ----- //

	// CurrentGameMode reference - set to one of the GameMode Concrete Strategies
	GameMode* CurrentGameMode;

	// Concrete GameMode strategies - solo instances
	AttractorMode* AttractorModeStrategy;
	OnePlayerMode* OnePlayerModeStrategy;
	TwoPlayerMode* TwoPlayerModeStrategy;

	// Concrete StartGameChecker strategies - solo instances
	StartGameChecker* CurrentStartGameChecker;
	StartGameCheckerOn* StartGameCheckerOnStrategy;
	StartGameCheckerOff* StartGameCheckerOffStrategy;

	// Managers
	GameEntityManager* myEntityManager;
	PlayerManager* myPlayerManager;
	WaveManager* myWaveManager;
	HUDManager* myHUDManager;
	ScoreManager* myScoreManager;
	SoundManager* mySoundManager;

public:
	static void SetGameMode(GameModeEnum newGameMode) { Instance().privSetGameMode(newGameMode); }
	static void TurnStartGameCheckerOn() { Instance().privTurnStartGameCheckerOn(); }
	static void TurnStartGameCheckerOff() { Instance().privTurnStartGameCheckerOff(); }
	static void GameInitialize() { return Instance().privGameInitialize(); }
	static void EndOfWaveCallback() { Instance().privEndOfWaveCallback(); }
	static void EndOfMushroomRegen() { Instance().privEndOfMushroomRegen(); }
	static void LossOfLifeCallback() { Instance().privLossOfLifeCallback(); }
	static GridManager* GridManagerAccessor() { return Instance().privGridManagerAccessor(); }
	static PlayerManager* PlayerManagerAccessor() { return Instance().privPlayerManagerAccessor(); }

};

#endif _GameManager