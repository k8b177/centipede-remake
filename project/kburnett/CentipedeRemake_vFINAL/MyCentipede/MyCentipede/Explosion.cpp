#include "Explosion.h"

#include "GameConstants.h"
#include "GridInfo.h"


void Explosion::Initialize(sf::Vector2f pos)
{
	MainSprite.SetFrame(0);
	Pos = pos;
	MainSprite.setPosition(Pos);
}

void Explosion::Update()
{
	MainSprite.setPosition(Pos);
	MainSprite.Update();


	if (MainSprite.IsLastAnimationFrame())
	{
		MarkForDestroy();
	}
}

void Explosion::Draw()
{
	WindowManager::Window().draw(MainSprite);
}