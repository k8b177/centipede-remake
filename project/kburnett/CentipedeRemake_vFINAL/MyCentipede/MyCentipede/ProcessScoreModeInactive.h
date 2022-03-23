// ProcessScoreModeInactive
// Katherine Burnett, September 2021

#ifndef _ProcessScoreModeInactive
#define _ProcessScoreModeInactive

#include "ProcessScoreMode.h"

class ProcessScoreModeInactive : public ProcessScoreMode
{
public:
	ProcessScoreModeInactive() = default;
	ProcessScoreModeInactive(const ProcessScoreModeInactive&) = delete;
	ProcessScoreModeInactive& operator= (const ProcessScoreModeInactive&) = default;
	~ProcessScoreModeInactive() = default;

	void ScoreUpdate(ScoreManager* pSM) override
	{
		// do nothing, no scores to process
	};

};
#endif _ProcessScoreModeInactive