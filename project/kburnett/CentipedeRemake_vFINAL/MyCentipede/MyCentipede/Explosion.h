// Explosion Base class

#ifndef _Explosion
#define _Explosion

#include "Game Components/TEAL/CommonElements.h"

class Explosion : public GameObject
{
public:
	// Big Four
	Explosion() = default;
	Explosion(const Explosion&) = delete;
	Explosion& operator=(const Explosion&) = delete;
	~Explosion() = default;


	virtual void Update();
	virtual void Draw();
	void Initialize(sf::Vector2f pos);

protected:
	AnimatedSprite MainSprite;
	sf::Vector2f Pos;

};

#endif _Explosion
