#ifndef _AIMoveDirectionDownLeft
#define _AIMoveDirectionDownLeft

#include "AIMoveDirection.h"


class AIMoveDirectionDownLeft : public AIMoveDirection
{
public:
	AIMoveDirectionDownLeft() = default;
	AIMoveDirectionDownLeft(const AIMoveDirectionDownLeft&) = delete;
	AIMoveDirectionDownLeft& operator= (const AIMoveDirectionDownLeft&) = delete;
	~AIMoveDirectionDownLeft() = default;

	void Move(Blaster* b) override;

};

#endif _AIMoveDirectionDownLeft