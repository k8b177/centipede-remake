// CentipedeHead
// Katherine Burnett, September 2021

#ifndef _CentipedeHead
#define _CentipedeHead

#include "CentipedeSegment.h"


class MushroomField;
class MoveState;

class CritterMoveMode;
class CentipedeSpawner;

class CentipedeHead : public CentipedeSegment
{
public:
	// Big Four
	CentipedeHead();
	CentipedeHead(const CentipedeHead&) = default;
	CentipedeHead& operator= (const CentipedeHead&) = default;
	~CentipedeHead() = default;

	//CentipedeHead(int speed, int startRow, int startCol);
	//CentipedeHead(CentipedeSegment* body);
	
	//static void CreateCentipedeHeadAtBody(CentipedeSegment* body);
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	void BulletHit();

	void MoveUpdate() override;
	void Freeze();
	void SetAnimationToPoison();
	void SetAnimationToNormal();

	void Initialize(int speed, int currentFrame, int row, int col, CentipedeSegment* nextSegment, const MoveState* moveState, CmdScore* pCmdScore, CmdSound* pCmdSoundKill, CentipedeSpawner* pCentipedeSpawner);

private:
	CritterMoveMode* pMoveMode;
	CentipedeSpawner* pCentipedeSpawner;
};

#endif _CentipedeHead