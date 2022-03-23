// SpiderScoreSpriteFactory

#ifndef _SpiderScoreSpriteFactory
#define _SpiderScoreSpriteFactory

#include "SFML/Graphics.hpp"
#include "SpiderScoreSpriteObjectPool.h"

#include "SpiderScoreSpriteEnum.h"

class GameObject;

class SpiderScoreSpriteFactory  // singleton
{
private:
	static SpiderScoreSpriteFactory* ptrInstance;

	SpiderScoreSpriteFactory();
	SpiderScoreSpriteFactory(const SpiderScoreSpriteFactory&) = delete;
	SpiderScoreSpriteFactory& operator=(const SpiderScoreSpriteFactory&) = delete;
	~SpiderScoreSpriteFactory() = default;

	static SpiderScoreSpriteFactory& Instance(); // Access reference

	SpiderScoreSpriteObjectPool myObjectPool;


	// Private NON_STATIC methods to perform actual work on member var
	void privCreateSpiderScoreSprite(SpiderScoreSpriteEnum type, sf::Vector2f pos);
	void privRecycleSpiderScoreSprite(GameObject* s);

public:

	static void CreateSpiderScoreSprite(SpiderScoreSpriteEnum type, sf::Vector2f pos)
	{
		Instance().privCreateSpiderScoreSprite(type, pos);
	};

	static void RecycleMushroom(GameObject* s)
	{
		Instance().privRecycleSpiderScoreSprite(s);
	}

	static void Terminate();
};


#endif _SpiderScoreSpriteFactory