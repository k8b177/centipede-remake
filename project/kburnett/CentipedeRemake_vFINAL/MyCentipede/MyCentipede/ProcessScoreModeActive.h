// ProcessScoreModeActive
// Katherine Burnett, September 2021

#ifndef _ProcessScoreModeActive
#define _ProcessScoreModeActive

#include "ProcessScoreMode.h"

class ProcessScoreModeActive : public ProcessScoreMode
{
public:
	ProcessScoreModeActive() = default;
	ProcessScoreModeActive(const ProcessScoreModeActive&) = delete;
	ProcessScoreModeActive& operator= (const ProcessScoreModeActive&) = default;
	~ProcessScoreModeActive() = default;

	void ScoreUpdate(ScoreManager* pSM) override;

};
#endif _ProcessScoreModeActive