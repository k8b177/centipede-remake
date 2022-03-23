#include "SpiderScoreSprite.h"
#include "GameConstants.h"

SpiderScoreSprite::SpiderScoreSprite()
{
	ThreeHundredRect = sf::IntRect(208, 0, 16, 8);
	SixHundredRect = sf::IntRect(208, 8, 16, 8);
	NineHundredRect = sf::IntRect(208, 16, 16, 8);


	MainSprite = sf::Sprite(ResourceManager::GetTexture("FullSpriteSheet"));

	MainSprite.setScale(GameConstants::SPRITE_SCALE * 2.0f, GameConstants::SPRITE_SCALE * 2.0f);
	
}

void SpiderScoreSprite::Initialize(SpiderScoreSpriteEnum type, sf::Vector2f pos)
{
	switch (type) {
	case SpiderScoreSpriteEnum::ThreeHundred:
		MainSprite.setTextureRect(ThreeHundredRect);
		MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
		break;
	case SpiderScoreSpriteEnum::SixHundred:
		MainSprite.setTextureRect(SixHundredRect);
		MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
		break;
	case SpiderScoreSpriteEnum::NineHundred:
		MainSprite.setTextureRect(NineHundredRect);
		MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
		break;
	}

	MainSprite.setPosition(pos);

	SetAlarm(0, 3.0f);
}

void SpiderScoreSprite::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void SpiderScoreSprite::Alarm0()
{
	MarkForDestroy();
}