// Mushroom
// Katherine Burnett, September 2021

#ifndef _Mushroom
#define _Mushroom

#include "Game Components/TEAL/CommonElements.h"

class CmdScore;
class CmdSound;

class GridManager;

class Mushroom : public GameObject
{
public:
	// Big Four
	Mushroom();
	Mushroom(const Mushroom&) = default;
	Mushroom& operator= (const Mushroom&) = default;
	~Mushroom() = default;

	void Initialize(int row, int col, sf::Vector2f pos, CmdScore* pPoisonShroomDeath, CmdScore* pRegularShroomDeath, CmdScore* pRegenPoints, CmdSound* pRegenSnd, GridManager* pGridManager);
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	void BulletHit();
	void Poison();
	void Eat();
	void RegenMushroom();

	AnimatedSprite MainSprite;
	int health;
	int col;
	int row;
	bool poisoned;

private:
	CollisionTools::TextureBitmap* bitmap;
	sf::Vector2f Pos;
	CmdScore* pPoisonShroomDeath;
	CmdScore* pRegularShroomDeath;
	CmdScore* pRegenPoints;
	CmdSound* pRegenSnd;
	GridManager* pGridManager;
};

#endif _Mushroom