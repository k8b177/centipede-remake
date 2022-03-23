// Bullet
// Katherine Burnett, September 2021

#include "Bullet.h"
#include "GameConstants.h"


#include "Spider.h"
#include "Flea.h"
#include "CentipedeHead.h"
#include "CentipedeBody.h"
#include "Scorpion.h"
#include "Blaster.h"


Bullet::Bullet()
{
	MainSprite.setTexture(ResourceManager::GetTexture("Bullet"));
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);


	bulletOffset = sf::Vector2f(0.0f, (float)MainSprite.getTextureRect().height);

	bitmap = ResourceManager::GetTextureBitmap("Bullet");
	SetCollider(MainSprite, bitmap, true);
	RegisterCollision<Bullet>(*this);
}

void Bullet::Initialize(Blaster* blaster)
{
	this->blaster = blaster;
	Pos = blaster->Pos - bulletOffset;
	MainSprite.setPosition(Pos);
	RegisterCollision<Bullet>(*this);
}

void Bullet::Update()
{
	Pos.y -= Game::FrameTime() * GameConstants::BULLET_SPEED;
	if (Pos.y < 0) // reaches top of screen
	{
		blaster->canFire = true;
		MarkForDestroy();
	}
	MainSprite.setPosition(Pos);
}

void Bullet::Draw()
{
	WindowManager::Window().draw(MainSprite);
}


void Bullet::Collision(Mushroom* other)
{
	blaster->canFire = true;
	other->BulletHit();
	MarkForDestroy();
}

void Bullet::Collision(Scorpion* other)
{
	blaster->canFire = true;
	other->BulletHit();
	MarkForDestroy();
}

void Bullet::Collision(Spider* other)
{
	blaster->canFire = true;
	other->BulletHit();
	MarkForDestroy();
}

void Bullet::Collision(CentipedeHead* other)
{
	blaster->canFire = true;
	other->BulletHit();
	MarkForDestroy();
}

void Bullet::Collision(CentipedeBody* other)
{
	blaster->canFire = true;
	other->BulletHit();
	MarkForDestroy();
}

void Bullet::Collision(Flea* other)
{
	blaster->canFire = true;
	other->BulletHit();
	MarkForDestroy();
}

void Bullet::Destroy()
{
	DeregisterCollision<Bullet>(*this);
}


