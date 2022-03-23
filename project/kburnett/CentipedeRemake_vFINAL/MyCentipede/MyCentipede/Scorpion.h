// Scorpion
// Katherine Burnett, September 2021

#ifndef _Scorpion
#define _Scorpion

#include "Critter.h"

class CmdScore;
class CmdSound;
class CmdSoundKill;
class GridManager;
class ScorpionSpawner;

class CritterMoveMode;

class Scorpion : public Critter
{
public:
	// Big Four
	Scorpion();
	Scorpion(const Scorpion&) = default;
	Scorpion& operator= (const Scorpion&) = default;
	~Scorpion() = default;

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	void BulletHit();
	void Inspect();

	void Initialize(sf::Vector2f pos, int speed, int row, int col, int direction, CmdScore* pCmdScore, CmdSound* pCmdSoundKill, GridManager* pGridManager, ScorpionSpawner* pScorpionSpawner);

	void MoveUpdate() override;
	void Freeze();

	AnimatedSprite MainSprite;

private:
	CollisionTools::TextureBitmap* bitmap;
	sf::Vector2f Pos;
	int direction; // 1 for right, -1 for left
	int speed;
	
	int row;
	int col;
	int frame;
	int FramesToMoveOneCell;

	int RightColBound;
	int LeftColBound;

	CmdScore* pCmdScore;
	CmdSound* pCmdSoundKill;
	GridManager* pGridManager;
	ScorpionSpawner* pScorpionSpawner;

	CritterMoveMode* pMoveMode;
};

#endif _Scorpion