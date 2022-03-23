// Flea
// Katherine Burnett, September 2021

#ifndef _Flea
#define _Flea


#include "Bullet.h"
#include "FleaSpawner.h"
#include "Mushroom.h"

#include "Critter.h"

class CmdScore;
class CmdSound;
class FleaSpawner;
class CritterMoveMode;

class Flea : public Critter
{
public:
	// Big Four
	Flea();
	Flea(const Flea&) = default;
	Flea& operator= (const Flea&) = default;
	~Flea() = default;

	void Initialize(sf::Vector2f, int col, float mushroomDropRate, CmdScore* pCmdScore, CmdSound* pCmdSoundKill, GridManager* pGridManager, FleaSpawner* pFleaSpawner);
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	void MoveUpdate() override;
	void Freeze();

	void BulletHit();
	void CheckToPlaceMushroom();
	bool DropMushroomCheck();
	void CheckBoundary();

	AnimatedSprite MainSprite;

private:
	CollisionTools::TextureBitmap* bitmap;
	sf::Vector2f Pos;
	
	int speed;
	int frame;
	int FramesToMoveOneCell;
	int row;
	int col;

	float dropRate;

	int health;

	CmdScore* pCmdScore;
	CmdSound* pCmdSoundKill;
	GridManager* pGridManager;
	FleaSpawner* pFleaSpawner;

	CritterMoveMode* pMoveMode;
};

#endif _Flea