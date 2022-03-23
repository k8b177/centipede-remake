// ProcessScoreMode
// Katherine Burnett, September 2021

#ifndef _ProcessScoreMode
#define _ProcessScoreMode

class ScoreManager;

class ProcessScoreMode
{
public:
	ProcessScoreMode() = default;
	ProcessScoreMode(const ProcessScoreMode&) = delete;
	ProcessScoreMode& operator= (const ProcessScoreMode&) = default;
	~ProcessScoreMode() = default;

	virtual void ScoreUpdate(ScoreManager* pSM) = 0;

};
#endif _ProcessScoreMode