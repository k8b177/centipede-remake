// ExplosionOneCellFactory

#include "ExplosionOneCellFactory.h"

#include "ExplosionOneCellObjectPool.h"
#include "ExplosionOneCell.h"


ExplosionOneCellFactory* ExplosionOneCellFactory::ptrInstance = nullptr;

ExplosionOneCellFactory::ExplosionOneCellFactory()
{
	
}

ExplosionOneCellFactory& ExplosionOneCellFactory::Instance()
{
	if (!ptrInstance)
		ptrInstance = new ExplosionOneCellFactory();
	return *ptrInstance;
}

void ExplosionOneCellFactory::privCreateOneCellExplosion(sf::Vector2f pos)
{
	ExplosionOneCell* e = myObjectPool.GetExplosionOneCell();

	// Declares that this object should be returned here (rather than deleted) when destroyed
	e->SetExternalManagement(RecycleOneCellExplosion);

	e->Initialize(pos);
}

void ExplosionOneCellFactory::privRecycleOneCellExplosion(GameObject* e)
{
	ExplosionOneCell* explosion = static_cast<ExplosionOneCell*>(e);
	myObjectPool.ReturnExplosionOneCell(explosion);
}

void ExplosionOneCellFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
