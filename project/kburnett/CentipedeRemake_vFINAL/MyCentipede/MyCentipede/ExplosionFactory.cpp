// ExplosionFactory

#include "ExplosionFactory.h"

#include "ExplosionOneCellObjectPool.h"
#include "ExplosionTwoCellObjectPool.h"
#include "ExplosionOneCell.h"
#include "ExplosionTwoCell.h"


ExplosionFactory* ExplosionFactory::ptrInstance = nullptr;

ExplosionFactory::ExplosionFactory()
{

}

ExplosionFactory& ExplosionFactory::Instance()
{
	if (!ptrInstance)
		ptrInstance = new ExplosionFactory();
	return *ptrInstance;
}

void ExplosionFactory::privCreateOneCellExplosion(sf::Vector2f pos)
{
	Explosion* e = myOneCellObjectPool.GetExplosionOneCell();

	// Declares that this object should be returned here (rather than deleted) when destroyed
	e->SetExternalManagement(RecycleOneCellExplosion);

	e->Initialize(pos);
}

void ExplosionFactory::privCreateTwoCellExplosion(sf::Vector2f pos)
{
	Explosion* e = myTwoCellObjectPool.GetExplosionTwoCell();

	// Declares that this object should be returned here (rather than deleted) when destroyed
	e->SetExternalManagement(RecycleTwoCellExplosion);

	e->Initialize(pos);
}

void ExplosionFactory::privRecycleOneCellExplosion(GameObject* e)
{
	ExplosionOneCell* explosion = static_cast<ExplosionOneCell*>(e);
	myOneCellObjectPool.ReturnExplosionOneCell(explosion);
}

void ExplosionFactory::privRecycleTwoCellExplosion(GameObject* e)
{
	ExplosionTwoCell* explosion = static_cast<ExplosionTwoCell*>(e);
	myTwoCellObjectPool.ReturnExplosionTwoCell(explosion);
}

void ExplosionFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
