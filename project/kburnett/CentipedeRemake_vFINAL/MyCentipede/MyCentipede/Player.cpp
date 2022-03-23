// Player
// Katherine Burnett, October 2021

#include "Player.h"
#include "MushroomFieldData.h"

Player::Player(): MyScore(0), MyLives(GameConstants::PLAYER_LIVES_MAX), MyWave(1), MyExtraLiveCounter(0)
{
	MyMushroomFieldData = new MushroomFieldData();
	nextPlayer = this;
}

void Player::InitializeNewMushroomFieldData()
{
	MyMushroomFieldData->InitializeMushroomFieldData();
}

MushroomFieldData* Player::GetMushroomFieldData()
{
	return MyMushroomFieldData;
}

void Player::SetNextPlayer(Player* p)
{
	nextPlayer = p;
}

int Player::GetWaveNumber()
{
	return MyWave;
}

void Player::IncrementWaveNumber()
{
	MyWave++;
}

void Player::DecrementLives()
{
	MyLives--;
}

int Player::GetLives()
{
	return MyLives;
}

int Player::GetScore()
{
	return MyScore;
}

void Player::SetScore(int x)
{
	MyScore = x;
}

void Player::SetWaveNumber(int n)
{
	MyWave = n;
}

void Player::SetLives(int n)
{
	MyLives = n;
}

void Player::SetMushroomDataAtRowCol(int row, int col, bool filled)
{
	MyMushroomFieldData->SetMushroomDataAtRowCol(row, col, filled);
}

int Player::GetExtraLifeCounter()
{
	return MyExtraLiveCounter;
}

void Player::SetExtraLifeCounter(int x)
{
	MyExtraLiveCounter = x;
}

Player::~Player()
{
	delete MyMushroomFieldData;
}