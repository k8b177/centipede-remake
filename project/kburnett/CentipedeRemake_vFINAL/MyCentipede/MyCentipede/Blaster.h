// Blaster
// Katherine Burnett, September 2021

#ifndef _Blaster
#define _Blaster

#include "Game Components/TEAL/CommonElements.h"
#include "GameConstants.h"

class Bullet;
class Mushroom;
class CentipedeBody;
class CentipedeHead;
class Spider;
class Scorpion;
class Flea;
class CmdSound;

class Blaster : public GameObject
{
public:
	// Big Four
	Blaster();
	Blaster(const Blaster&) = default;
	Blaster& operator= (const Blaster&) = default;
	~Blaster();

	virtual void Draw();
	virtual void Destroy();

	void Initialize(CmdSound* pDeathSnd);
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	void Move(int xDirection, int yDirection);
	void MovementClamp();
	void Fire();
	sf::Vector2f GetPos();

	virtual void Collision(GameObject* other) {};
	void Collision(Mushroom* other);
	void Collision(CentipedeHead* critter);
	void Collision(CentipedeBody* critter);
	void Collision(Spider* spider);
	void Collision(Flea* flea);
	void Collision(Scorpion* scorpion);

	sf::Vector2f Pos;
	sf::Vector2f StartingPos;
	bool canFire;
	Bullet* bullet;

	sf::Sprite MainSprite;

private:
	void PlayerLoseLife();

	sf::Vector2f PrevPos;
	float speed;
	float TOP_PLAYERAREA;
	CollisionTools::TextureBitmap bitmap;
	float halfTextureSize;
	float RightBound;
	float LeftBound;
	float TopBound;
	float BottomBound;

	CmdSound* pDeathSnd;
};

#endif _Blaster