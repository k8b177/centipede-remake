#ifndef _AIMoveDirectionDownRight
#define _AIMoveDirectionDownRight

#include "AIMoveDirection.h"


class AIMoveDirectionDownRight : public AIMoveDirection
{
public:
	AIMoveDirectionDownRight() = default;
	AIMoveDirectionDownRight(const AIMoveDirectionDownRight&) = delete;
	AIMoveDirectionDownRight& operator= (const AIMoveDirectionDownRight&) = delete;
	~AIMoveDirectionDownRight() = default;

	void Move(Blaster* b) override;

};

#endif _AIMoveDirectionDownRight