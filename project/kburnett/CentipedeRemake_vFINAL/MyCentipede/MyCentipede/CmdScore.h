// CmdScore
// Katherine Burnett, 2021

#ifndef _CmdScore
#define _CmdScore

class Spider;

class ScoreManager;

class CmdScore
{
public:
	// Big Four
	CmdScore() = default;
	CmdScore(const CmdScore&) = delete;
	CmdScore& operator= (const CmdScore&) = delete;
	~CmdScore() = default;

	// Note: the Excecute method must NOT have _any_ paramters
	virtual void Execute() = 0;

	virtual void SendToManager() = 0;
	virtual void SetSpiderPointer(Spider* s) = 0;
};

#endif _CmdScore
