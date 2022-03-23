// CentipedeTracker

#ifndef _CentipedeTracker
#define _CentipedeTracker

#include "GameConstants.h"

class CentipedeSegment;


class CentipedeTracker // singleton
{
private:
	static CentipedeTracker* ptrInstance;

	CentipedeTracker();
	CentipedeTracker(const CentipedeTracker&) = delete;
	CentipedeTracker& operator= (const CentipedeTracker&) = delete;
	~CentipedeTracker() = default;

	static CentipedeTracker& Instance();	    // Access reference (all public methods will be static)

	// private vars
	bool CentipedeTrackerArray[GameConstants::GRID_SIZE];

	// private methods
	void privSetCentipedeTrackerArrayAt(int row, int col, bool value);
	bool privGetCentipedeTrackerArrayAt(int row, int col);

public:
	static void SetCentipedeTrackerArrayAt(int row, int col, bool value) { Instance().privSetCentipedeTrackerArrayAt(row, col, value); }
	static bool GetCentipedeTrackerArrayAt(int row, int col) { return Instance().privGetCentipedeTrackerArrayAt(row, col); }
};

#endif _CentipedeTracker