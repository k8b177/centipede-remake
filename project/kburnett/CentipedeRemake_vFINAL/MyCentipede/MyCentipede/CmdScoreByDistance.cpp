// CmdScoreByDistance

#include "CmdScoreByDistance.h"
#include "ScoreManager.h"
#include "PlayerManager.h"
#include "Spider.h"
#include "Blaster.h"
#include "SpiderScoreSpriteEnum.h"
#include "SpiderScoreSpriteFactory.h"

//#include "BlasterFactory.h"

CmdScoreByDistance::CmdScoreByDistance(int dn, int dm, int df, int vn, int vm, int vf, ScoreManager* pScoreManager, Blaster* blaster)
	: dNear_squared(dn), dMed_squared(dm), dFar_squared(df), vNear(vn), vMed(vm), vFar(vf),
	pScoreManager(pScoreManager), spider(nullptr), blaster(blaster)
{
	this->spider = nullptr;
	this->blaster = blaster;
}


void CmdScoreByDistance::Execute()
{
	// find distance between blaster and spider;
	int distanceBetweenBlasterAndSpider_squared = GetDistanceBetweenBlasterAndSpider();
	ConsoleMsg::WriteLine("Distance to Player = " + std::to_string(distanceBetweenBlasterAndSpider_squared));

	int val;
	SpiderScoreSpriteEnum type;

	// processing distance to score:
	if (distanceBetweenBlasterAndSpider_squared <= dNear_squared)
	{
		printf("\t\tNear range detected:\n");
		type = SpiderScoreSpriteEnum::ThreeHundred;
		val = vNear;
	}
	else if (distanceBetweenBlasterAndSpider_squared <= dMed_squared)
	{
		printf("\t\tMedium range detected:\n");
		type = SpiderScoreSpriteEnum::SixHundred;
		val = vMed;
	}
	else
	{
		printf("\t\tFar range detected:\n");
		type = SpiderScoreSpriteEnum::NineHundred;
		val = vFar;
	}

	SpiderScoreSpriteFactory::CreateSpiderScoreSprite(type, spider->GetPos());

	pScoreManager->AddScore(vNear);
}

void CmdScoreByDistance::SendToManager()
{
	pScoreManager->SendScoreCmd(this);
}

int CmdScoreByDistance::GetDistanceBetweenBlasterAndSpider()
{
	sf::Vector2f spiderPos = spider->GetPos();
	sf::Vector2f blasterPos = blaster->GetPos();

	ConsoleMsg::WriteLine("SpiderPos (x, y)= (" + std::to_string(spiderPos.x) + ", " + std::to_string(spiderPos.y) + ")" );
	ConsoleMsg::WriteLine("BlasterPos (x, y)= (" + std::to_string(blasterPos.x) + ", " + std::to_string(blasterPos.y) + ")");

	int dist_squared = (int)((spiderPos.x - blasterPos.x)*(blasterPos.x - spiderPos.x) + (blasterPos.y - spiderPos.y)*(blasterPos.y - spiderPos.y));
	return dist_squared;
}

void CmdScoreByDistance::SetSpiderPointer(Spider* s)
{
	this->spider = s;
}