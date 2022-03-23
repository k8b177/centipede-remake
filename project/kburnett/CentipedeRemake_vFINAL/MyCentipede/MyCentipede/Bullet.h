// Bullet
// Katherine Burnett, September 2021

#ifndef _Bullet
#define _Bullet

#include "Game Components/TEAL/CommonElements.h"

class Blaster;
class Mushroom;
class Scorpion;
class Spider;
class CentipedeHead;
class Flea;
class CentipedeBody;

class Bullet : public GameObject
{
public:
	// Big Four
	Bullet();
	Bullet(const Bullet&) = default;
	Bullet& operator= (const Bullet&) = default;
	~Bullet() = default;

	void Initialize(Blaster* blaster);
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	virtual void Collision(GameObject* other) {};
	void Collision(Mushroom* other);
	void Collision(Scorpion* other);
	void Collision(Spider* other);
	void Collision(CentipedeHead* other);
	void Collision(CentipedeBody* other);
	void Collision(Flea* other);

private:
	sf::Sprite MainSprite;
	sf::Vector2f Pos;
	sf::Vector2f bulletOffset;
	CollisionTools::TextureBitmap bitmap;
	Blaster* blaster;
};

#endif _Bullet