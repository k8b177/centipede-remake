// Blaster
// Katherine Burnett, September 2021

#include "Blaster.h"
#include "BulletFactory.h"
#include "GameManager.h"
#include "CentipedeHead.h"
#include "CentipedeBody.h"
#include "Scorpion.h"
#include "Flea.h"
#include "Spider.h"
#include "CmdSound.h"
#include "GridInfo.h"
#include "ExplosionFactory.h"

Blaster::Blaster()
{
	MainSprite.setTexture(ResourceManager::GetTexture("Blaster"));
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(GameConstants::SPRITE_SCALE, GameConstants::SPRITE_SCALE);
	MainSprite.setPosition(Pos);

	StartingPos = sf::Vector2f(WindowManager::Window().getView().getSize().x / 2.0f, WindowManager::Window().getView().getSize().y - MainSprite.getTextureRect().height / 2.0f);

	bitmap = ResourceManager::GetTextureBitmap("Blaster");
	SetCollider(MainSprite, bitmap, true);

	halfTextureSize = MainSprite.getTextureRect().width / 2.0f;

	TopBound = WindowManager::Window().getView().getSize().y - GameConstants::CELLSIZE * (GridInfo::ROWS_IN_PLAYER_AREA) + halfTextureSize;
	BottomBound = WindowManager::Window().getView().getSize().y - halfTextureSize;
	RightBound = WindowManager::Window().getView().getSize().x - halfTextureSize;
	LeftBound = halfTextureSize;

	speed = GameConstants::BLASTER_SPEED;
}

void Blaster::Initialize(CmdSound* pDeathSnd)
{
	Pos = StartingPos;
	MainSprite.setPosition(Pos);
	RegisterCollision<Blaster>(*this);
	canFire = true; 

	this->pDeathSnd = pDeathSnd;
}

Blaster::~Blaster()
{
}


void Blaster::MoveLeft()
{
	Move(-1, 0);
}
void Blaster::MoveRight()
{
	Move(1, 0);
}
void Blaster::MoveUp()
{
	Move(0, -1);
}
void Blaster::MoveDown()
{
	Move(0, 1);
}

void Blaster::Move(int xDirection, int yDirection)
{
	PrevPos = Pos;
	Pos += sf::Vector2f(speed*xDirection, speed*yDirection);
	MovementClamp();
	MainSprite.setPosition(Pos);
}

void Blaster::MovementClamp()
{
	Tools::Clamp<float>(Pos.x, LeftBound, RightBound);
	Tools::Clamp<float>(Pos.y, TopBound, BottomBound);
}

void Blaster::Fire()
{
	if (canFire)
	{
		canFire = false;
		BulletFactory::CreateBullet(); 
	}
}


void Blaster::Draw()
{
	WindowManager::Window().draw(MainSprite);
}


void Blaster::Collision(Mushroom* other)
{
	Pos = PrevPos;
	MainSprite.setPosition(Pos);
}

void Blaster::Collision(CentipedeHead* centipedeHead)
{
	centipedeHead->MarkForDestroy();
	PlayerLoseLife();
}
void Blaster::Collision(CentipedeBody* centipedeBody)
{
	centipedeBody->MarkForDestroy();
	PlayerLoseLife();
}
void Blaster::Collision(Spider* spider)
{
	spider->MarkForDestroy();
	PlayerLoseLife();
}
void Blaster::Collision(Flea* flea)
{
	flea->MarkForDestroy();
	PlayerLoseLife();
}
void Blaster::Collision(Scorpion* scorpion)
{
	scorpion->MarkForDestroy();
	PlayerLoseLife();
}

sf::Vector2f Blaster::GetPos()
{
	return Pos;
}

void Blaster::PlayerLoseLife()
{
	MarkForDestroy();
	ExplosionFactory::CreateTwoCellExplosion(Pos);
	pDeathSnd->SendToManager();
	GameManager::LossOfLifeCallback();
}

void Blaster::Destroy()
{
	DeregisterCollision<Blaster>(*this);
}
