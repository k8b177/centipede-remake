#include "ExplosionOneCell.h"

#include "GameConstants.h"
#include "GridInfo.h"

ExplosionOneCell::ExplosionOneCell()
{
	// Sprite Setup

	sf::Texture texture;

	MainSprite = AnimatedSprite(ResourceManager::GetTexture("ExplosionOneCell"), 3, 2, GameConstants::FPS_ANIMATION * 5);
	MainSprite.SetAnimation(0, 5);
	MainSprite.setScale(GameConstants::SPRITE_SCALE * 2.0f, GameConstants::SPRITE_SCALE * 2.0f);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);

}