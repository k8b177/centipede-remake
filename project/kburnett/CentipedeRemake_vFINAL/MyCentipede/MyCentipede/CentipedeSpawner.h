// CentipedeSpawner
// Katherine Burnett, September 2021

#ifndef _CentipedeSpawner
#define _CentipedeSpawner

#include "Game Components/TEAL/CommonElements.h"
#include "ActiveStatusEnum.h"

class CentipedeSegment;
class MoveState;

class ActiveMoveMode;
class FrozenMoveMode;

class HeadSpawnCheck;
class HeadSpawnCheck_Active;
class HeadSpawnCheck_Inactive;

class CentipedeSpawner : public GameObject
{
public:
	CentipedeSpawner() = delete;
	CentipedeSpawner(const CentipedeSpawner&) = delete;
	CentipedeSpawner& operator= (const CentipedeSpawner&) = delete;
	~CentipedeSpawner() = default;

	CentipedeSpawner(ActiveMoveMode* pActiveMoveMode, FrozenMoveMode* pFrozenMoveMode);

	const MoveState* GetRandCentipedeDirection_StartAtTop();
	const MoveState* GetRandCentipedeDirection_StartAtSide(int& columnReturned);
	void SpawnNewCentipedeAtTop(int length, int speed);
	void SpawnCentipedeSoloHeadAtTop(int row, int col);
	void SpawnCentipedeSoloHeadInPlayerArea();
	void InitializeWaveSettings(int centipedeSpeed, int centipedeLength, ActiveStatus centipedeSoloHeadActive, int centipedeSoloHeadCount, ActiveStatus centipedeSoloHeadInPlayerAreaActive, int centipedeSoloHeadInPlayerAreaCount);
	void FreezeAllCentipedes();
	void DestroyAllActiveCentipedes();
	void CheckSpawnNewHead();
	void DecrementCurrentHeadsInPlayerArea();

	ActiveMoveMode* GetActiveMoveMode();
	FrozenMoveMode* GetFrozenMoveMode();

	virtual void Alarm0();
	virtual void Destroy();

	int CurrentCount_HeadsInPlayerArea;

private:
	// private vars
	int CentipedeSpeed;
	int CentipedeLength;
	ActiveStatus CentipedeSoloHeadActive;
	int CentipedeSoloHeadCount;
	ActiveStatus CentipedeSoloHeadInPlayerAreaActive;
	int CentipedeSoloHeadInPlayerAreaCount;

	ActiveMoveMode* pActiveMoveMode;
	FrozenMoveMode* pFrozenMoveMode;

	HeadSpawnCheck* myHeadSpawnCheck;
	HeadSpawnCheck_Active* pHeadSpawnCheckActive;
	HeadSpawnCheck_Inactive* pHeadSpawnCheckInactive;

};

#endif _CentipedeSpawner
