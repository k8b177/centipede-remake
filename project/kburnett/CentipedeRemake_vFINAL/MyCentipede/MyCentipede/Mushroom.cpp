// Mushroom
// Katherine Burnett, September 2021

#include "Mushroom.h"
#include "GameConstants.h"

#include "CmdScore.h"
#include "CmdSound.h"
#include "GridManager.h"

#include "ExplosionFactory.h"

Mushroom::Mushroom()
{
	// Sprite Setup
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Mushroom"), 4, 2);
	MainSprite.SetAnimation(0, 7);
	MainSprite.setScale(GameConstants::SPRITE_SCALE, GameConstants::SPRITE_SCALE);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);

	// Collider Setup
	bitmap = &ResourceManager::GetTextureBitmap("Mushroom");
	SetCollider(MainSprite, *bitmap);
	RegisterCollision<Mushroom>(*this);

	// Other info
	health = 0;
	poisoned = false;
}

void Mushroom::Initialize(int row, int col, sf::Vector2f pos, CmdScore* pPoisonShroomDeath, CmdScore* pRegularShroomDeath, CmdScore* pRegenPoints, CmdSound* pRegenSnd, GridManager* pGridManager)
{
	// Row/Col Setup
	this->row = row;
	this->col = col;

	// Position Setup
	Pos = pos;
	MainSprite.setPosition(Pos);

	// Other info
	health = 0;
	poisoned = false;

	//Animation info
	MainSprite.SetFrame(0);

	// Score Command info
	this->pPoisonShroomDeath = pPoisonShroomDeath;
	this->pRegularShroomDeath = pRegularShroomDeath;
	this->pRegenPoints = pRegenPoints;

	// Sound info
	this->pRegenSnd = pRegenSnd;

	// GridManager info
	this->pGridManager = pGridManager;

	// Re-register Collison
	RegisterCollision<Mushroom>(*this);
}

void Mushroom::Update()
{
}

void Mushroom::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void Mushroom::Destroy()
{
	DeregisterCollision<Mushroom>(*this);
}

void Mushroom::BulletHit()
{
	// Adding to health (range is 0-4, where mushroom with health 4 is destroyed)
	health += 1;
	if (health >= GameConstants::MUSHROOM_DEAD_HEALTH)
	{
		// Removing from current mushroom field
		pGridManager->RemoveMushroomFromField(this);

		// Sending correct score based on poison
		if (poisoned)
			pPoisonShroomDeath->SendToManager();
		else
			pRegularShroomDeath->SendToManager();

		// Destroying game object (routed to recycle)
		MarkForDestroy();
	}
	else
		MainSprite.NextFrame();
}

void Mushroom::Poison()
{
	poisoned = true;
	MainSprite.SetFrame(4 + health);
}

void Mushroom::Eat()
{
	pGridManager->RemoveMushroomFromField(this);
	MarkForDestroy();
}


void Mushroom::RegenMushroom()
{
	ExplosionFactory::CreateOneCellExplosion(Pos);
	pRegenSnd->SendToManager();
	pRegenPoints->SendToManager();
	poisoned = false;
	health = 0;
	MainSprite.SetFrame(0);
}
