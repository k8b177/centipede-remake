// StartGameCheckerOn - Concrete Strategy for StartGameChecker

#ifndef _StartGameCheckerOn
#define _StartGameCheckerOn

#include "StartGameChecker.h"

class StartGameCheckerOn : public StartGameChecker
{
public:
	// Big Four
	StartGameCheckerOn() = default;
	StartGameCheckerOn(const StartGameCheckerOn&) = delete;
	StartGameCheckerOn& operator=(const StartGameCheckerOn&) = delete;
	~StartGameCheckerOn() = default;

	void CheckToStart() override;
};

#endif _StartGameCheckerOn