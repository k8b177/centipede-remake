// SpiderScoreSprite

#ifndef _SpiderScoreSprite
#define _SpiderScoreSprite

#include "Game Components/TEAL/CommonElements.h"
#include "SpiderScoreSpriteEnum.h"

class SpiderScoreSprite : public GameObject
{
public:
	SpiderScoreSprite();
	SpiderScoreSprite(const SpiderScoreSprite&) = delete;
	SpiderScoreSprite& operator= (const SpiderScoreSprite&) = delete;
	~SpiderScoreSprite() = default;

	void Initialize(SpiderScoreSpriteEnum type, sf::Vector2f pos);
	virtual void Draw();
	virtual void Alarm0();

private:
	sf::Vector2f Pos;
	sf::Sprite MainSprite;

	sf::IntRect ThreeHundredRect;
	sf::IntRect SixHundredRect;
	sf::IntRect NineHundredRect;
};


#endif _SpiderScoreSprite
