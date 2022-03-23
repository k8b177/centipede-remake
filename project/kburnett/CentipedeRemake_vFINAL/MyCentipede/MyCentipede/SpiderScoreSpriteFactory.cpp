// SpiderScoreSpriteFactory

#include "SpiderScoreSpriteFactory.h"

#include "SpiderScoreSprite.h"

SpiderScoreSpriteFactory* SpiderScoreSpriteFactory::ptrInstance = nullptr;

SpiderScoreSpriteFactory::SpiderScoreSpriteFactory()
{

}

SpiderScoreSpriteFactory& SpiderScoreSpriteFactory::Instance()
{
	if (!ptrInstance)
		ptrInstance = new SpiderScoreSpriteFactory();
	return *ptrInstance;
}


void SpiderScoreSpriteFactory::privCreateSpiderScoreSprite(SpiderScoreSpriteEnum type, sf::Vector2f pos)
{
	SpiderScoreSprite* s = myObjectPool.GetSpiderScoreSprite();

	// Declares that this object should be returned here (rather than deleted) when destroyed
	s->SetExternalManagement(RecycleMushroom);

	s->Initialize(type, pos);
}

void SpiderScoreSpriteFactory::privRecycleSpiderScoreSprite(GameObject* s)
{
	myObjectPool.ReturnSpiderScoreSprite(static_cast<SpiderScoreSprite*>(s));
}


void SpiderScoreSpriteFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
