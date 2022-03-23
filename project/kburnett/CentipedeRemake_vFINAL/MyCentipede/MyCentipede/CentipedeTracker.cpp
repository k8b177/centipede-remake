// CentipedeTracker

#include "CentipedeTracker.h"
#include "MushroomField.h"

CentipedeTracker* CentipedeTracker::ptrInstance = nullptr;

CentipedeTracker::CentipedeTracker()
{
	for (int i = 0; i < GameConstants::GRID_SIZE; i++)
	{
		CentipedeTrackerArray[i] = false;
	}
}

CentipedeTracker& CentipedeTracker::Instance()
{
	if (!ptrInstance)
		ptrInstance = new CentipedeTracker();
	
	return *ptrInstance;
}

void CentipedeTracker::privSetCentipedeTrackerArrayAt(int row, int col, bool value)
{
	int index = MushroomField::Coordinate2DTo1D(col, row);
	CentipedeTrackerArray[index] = value;
}

bool CentipedeTracker::privGetCentipedeTrackerArrayAt(int row, int col)
{
	int index = MushroomField::Coordinate2DTo1D(col, row);
	return CentipedeTrackerArray[index];
}