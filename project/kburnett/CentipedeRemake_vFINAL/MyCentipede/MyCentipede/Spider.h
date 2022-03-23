// Scorpion
// Katherine Burnett, September 2021

#ifndef _Spider
#define _Spider

#include "Critter.h"
#include "SpiderSpawner.h"

class SpiderSpawner;
class GridManager;
class CmdScore;
class CmdSound;
class CritterMoveMode;

class Spider : public Critter
{
public:
	// Big Four
	Spider();
	Spider(const Spider&) = default;
	Spider& operator= (const Spider&) = default;
	~Spider() = default;

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	void BulletHit();
	sf::Vector2f GetPos();

	void MoveUpdate() override;
	void Freeze();


	void Initialize(sf::Vector2f pos, int speed, int row, int col, int overallXDirection, CmdScore* pCmdScore, CmdSound* pCmdSoundKill, GridManager* pGridManager, SpiderSpawner* pSpiderSpawner);

private:

	void ChangeDirection();
	int ChooseNewRow();
	void ChooseVerticalOrDiagonal();
	void Inspect();

	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap* bitmap;
	sf::Vector2f Pos;

	int overallXDirection; // 1 for right, -1 for left
	int xDirection; // 1 for right, -1 for left
	int yDirection; // -1 for up, 1 for down

	int row;
	int col;
	int destinationRow;
	int RightColBound;
	int LeftColBound;
	int frame;
	int framesToMoveOneCell;

	int speed;

	CmdScore* pCmdScore;
	CmdSound* pCmdSoundKill;
	SpiderSpawner* pSpiderSpawner;
	GridManager* pGridManager;

	CritterMoveMode* pMoveMode;
};

#endif _Scorpion