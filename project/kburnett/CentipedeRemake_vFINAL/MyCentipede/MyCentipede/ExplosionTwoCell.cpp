#include "ExplosionTwoCell.h"

#include "GameConstants.h"
#include "GridInfo.h"

ExplosionTwoCell::ExplosionTwoCell()
{
	// Sprite Setup
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("ExplosionTwoCell"), 4, 2, GameConstants::FPS_ANIMATION);
	MainSprite.SetAnimation(0, 7);
	MainSprite.setScale(GameConstants::SPRITE_SCALE, GameConstants::SPRITE_SCALE);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);

}