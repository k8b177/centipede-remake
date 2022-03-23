#ifndef _AIMoveDirectionStop
#define _AIMoveDirectionStop

#include "AIMoveDirection.h"


class AIMoveDirectionStop : public AIMoveDirection
{
public:
	AIMoveDirectionStop() = default;
	AIMoveDirectionStop(const AIMoveDirectionStop&) = delete;
	AIMoveDirectionStop& operator= (const AIMoveDirectionStop&) = delete;
	~AIMoveDirectionStop() = default;

	void Move(Blaster* b) override
	{
		// do nothing
	}

};

#endif _AIMoveDirectionStop