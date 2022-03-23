// CmdScoreByDistance

#ifndef _CmdScoreByDistance
#define _CmdScoreByDistance

#include "CmdScore.h"

class Blaster;

class CmdScoreByDistance : public CmdScore
{
public:
	// Big Four
	CmdScoreByDistance() = delete;
	CmdScoreByDistance(const CmdScoreByDistance&) = default;
	CmdScoreByDistance& operator= (const CmdScoreByDistance&) = default;
	~CmdScoreByDistance() = default;

	CmdScoreByDistance(int dNear, int dMed, int dFar, int vNear, int vMed, int vFar, ScoreManager* pScoreManager, Blaster* blaster);

	virtual void Execute() override;
	virtual void SendToManager() override;
	virtual void SetSpiderPointer(Spider* s) override;

private:
	int dNear_squared;
	int dMed_squared;
	int dFar_squared;
	int vNear;
	int vMed;
	int vFar;

	Spider* spider;
	Blaster* blaster;

	ScoreManager* pScoreManager;

	int GetDistanceBetweenBlasterAndSpider();
};

#endif _CmdScoreByDistance
