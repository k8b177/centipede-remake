// CmdScoreValue
// Katherine Burnett, 2021

#ifndef _CmdScoreValue
#define _CmdScoreValue

#include "CmdScore.h"

class CmdScoreValue : public CmdScore
{
protected:
	int points;	// points to add

public:
	// Big Four
	CmdScoreValue() = delete;
	CmdScoreValue(const CmdScoreValue&) = default;
	CmdScoreValue& operator= (const CmdScoreValue&) = default;
	~CmdScoreValue() = default;

	CmdScoreValue(int val, ScoreManager* pScoreManager);

	virtual void Execute() override;

	virtual void SendToManager() override;
	virtual void SetSpiderPointer(Spider* s) override;

private:
	ScoreManager* pScoreManager;

};

#endif _CmdScoreValue
