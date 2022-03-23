#include "BlasterSpawner.h"
#include "BlasterFactory.h"
#include "BulletFactory.h"
#include "Blaster.h"
#include "Game Components/TEAL/CommonElements.h"

BlasterSpawner::BlasterSpawner()
{
	BlasterFactory::CreateBlaster();
	BulletFactory::SetBlaster(BlasterFactory::GetBlaster());
}

void BlasterSpawner::SpawnBlaster()
{
	BlasterFactory::CreateBlaster();
}

BlasterSpawner::~BlasterSpawner()
{

}

void BlasterSpawner::ResetBlasterPos()
{
	Blaster* b = BlasterFactory::GetBlaster();
	b->Pos = b->StartingPos;
	b->MainSprite.setPosition(b->Pos);

}