// Player
// Katherine Burnett, October 2021

#ifndef _Player
#define _Player

class MushroomFieldData;

class Player
{
public:
	Player();
	Player(const Player&) = delete;
	Player& operator= (const Player&) = delete;
	~Player();

	void InitializeNewMushroomFieldData();
	MushroomFieldData* GetMushroomFieldData();
	void SetNextPlayer(Player* p);
	int GetWaveNumber();
	void IncrementWaveNumber();
	void DecrementLives();
	int GetLives();
	int GetScore();
	void SetScore(int x);
	void SetWaveNumber(int n);
	void SetLives(int n);
	void SetMushroomDataAtRowCol(int row, int col, bool filled);
	int GetExtraLifeCounter();
	void SetExtraLifeCounter(int x);

private:
	int MyScore;
	int MyLives;
	int MyWave;
	int MyExtraLiveCounter;

	MushroomFieldData* MyMushroomFieldData;
	Player* nextPlayer;
};

#endif _Player