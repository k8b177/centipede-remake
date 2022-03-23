// StartGameChecker - Strategy

#ifndef _StartGameChecker
#define _StartGameChecker

class StartGameChecker
{
public:
	// Big Four
	StartGameChecker() = default;
	StartGameChecker(const StartGameChecker&) = delete;
	StartGameChecker& operator=(const StartGameChecker&) = delete;
	~StartGameChecker() = default;

	virtual void CheckToStart() = 0;
};

#endif _StartGameChecker
