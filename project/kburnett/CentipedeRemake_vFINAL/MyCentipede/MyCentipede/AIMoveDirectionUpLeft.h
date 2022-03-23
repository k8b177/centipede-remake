#ifndef _AIMoveDirectionUpLeft
#define _AIMoveDirectionUpLeft

#include "AIMoveDirection.h"


class AIMoveDirectionUpLeft : public AIMoveDirection
{
public:
	AIMoveDirectionUpLeft() = default;
	AIMoveDirectionUpLeft(const AIMoveDirectionUpLeft&) = delete;
	AIMoveDirectionUpLeft& operator= (const AIMoveDirectionUpLeft&) = delete;
	~AIMoveDirectionUpLeft() = default;

	void Move(Blaster* b) override;

};

#endif _AIMoveDirectionUpLeft