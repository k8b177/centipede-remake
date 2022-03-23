// CentipedeBody

#ifndef _CentipedeBody
#define _CentipedeBody

#include "CentipedeSegment.h"

class CritterMoveMode;
class CentipedeSpawner;

class CentipedeBody : public CentipedeSegment
{
public:
	// Big Four
	CentipedeBody();
	CentipedeBody(const CentipedeBody&) = default;
	CentipedeBody& operator= (const CentipedeBody&) = default;
	~CentipedeBody() = default;

	void Initialize(int speed, int currentFrame, int row, int col, const MoveState* moveState, CmdScore* pCmdScore, CmdSound* pCmdSoundKill, CentipedeSpawner* pCentipedeSpawner);

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	void MoveUpdate() override;
	void Freeze();

private:
	CritterMoveMode* pMoveMode;
	CentipedeSpawner* pCentipedeSpawner;
};

#endif _CentipedeBody


