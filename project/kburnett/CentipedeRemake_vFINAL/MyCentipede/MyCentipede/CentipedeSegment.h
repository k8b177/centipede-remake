// CentipedeSegment

#ifndef _CentipedeSegment
#define _CentipedeSegment

#include "Critter.h"

class MoveState;
class CmdScore;
class CmdSound;

class CentipedeSegment : public Critter
{
public:
	// Big Four
	CentipedeSegment();
	CentipedeSegment(const CentipedeSegment&) = default;
	CentipedeSegment& operator= (const CentipedeSegment&) = default;
	~CentipedeSegment() = default;

	int GetRow();
	int GetCol();
	void SetRow(int newRow);
	void SetCol(int newCol);

	void BulletHit();
	void PlaceMushroom();
	void Split();
	void SetState(const MoveState* state);
	void PassAlongInfo();

	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap* bitmap;

	int row;
	int col;

	CentipedeSegment* pSegmentBehind;
	CentipedeSegment* pSegmentAhead;


	sf::Vector2f Pos;

	int speed;
	int frame;
	int NumFramesToMoveOneCell;
	const MoveState* pCurrentState;
	sf::Vector2f CurrCellPos;

	CmdScore* pCmdScore;
	CmdSound* pCmdSoundKill;
};

#endif _CentipedeSegment
