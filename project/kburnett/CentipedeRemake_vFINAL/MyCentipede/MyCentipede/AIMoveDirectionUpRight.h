#ifndef _AIMoveDirectionUpRight
#define _AIMoveDirectionUpRight

#include "AIMoveDirection.h"


class AIMoveDirectionUpRight : public AIMoveDirection
{
public:
	AIMoveDirectionUpRight() = default;
	AIMoveDirectionUpRight(const AIMoveDirectionUpRight&) = delete;
	AIMoveDirectionUpRight& operator= (const AIMoveDirectionUpRight&) = delete;
	~AIMoveDirectionUpRight() = default;

	void Move(Blaster* b) override;

};

#endif _AIMoveDirectionUpRight