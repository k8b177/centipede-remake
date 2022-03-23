// StartGameCheckerOff - Concrete Strategy for StartGameChecker

#ifndef _StartGameCheckerOff
#define _StartGameCheckerOff

#include "StartGameChecker.h"

class StartGameCheckerOff : public StartGameChecker
{
public:
	// Big Four
	StartGameCheckerOff() = default;
	StartGameCheckerOff(const StartGameCheckerOff&) = delete;
	StartGameCheckerOff& operator=(const StartGameCheckerOff&) = delete;
	~StartGameCheckerOff() = default;

	void CheckToStart() override {
		// do nothing
	}
};

#endif _StartGameCheckerOff