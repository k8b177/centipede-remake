// MushroomRegen

#include "MushroomRegen.h"
#include "PlayerManager.h"
#include "Player.h"
#include "ScoreManager.h"
#include "CmdScore.h"

#include "Mushroom.h"
#include "GridManager.h"
#include "GameManager.h"

MushroomRegen::MushroomRegen(GridManager* pGridManager)
	:r(0), c(0), pGridManager(pGridManager), pCmdScore(nullptr)
{
	
}

void MushroomRegen::StartRegen()
{
	SetAlarm(0, 1.5f);
}

void MushroomRegen::CheckNextMushroom()
{
	while (c <= GridInfo::RIGHT_COLUMN)
	{
		while (r <= GridInfo::TOP_ROW)
		{
			Mushroom* m = pGridManager->GetMushroomAt(r, c);
			if (m!= nullptr)
			{
				if (m->health > 0 || m->poisoned)
				{
					m->RegenMushroom();
					r++;
					SetAlarm(0, 0.25f);
					return;
				}
			}
			r++;
		}
		r = 0;
		c++;
	}
	SetAlarm(1, 1.5f);
}

void MushroomRegen::Alarm0()
{
	CheckNextMushroom();
}

void MushroomRegen::Alarm1()
{
	GameManager::EndOfMushroomRegen();
}