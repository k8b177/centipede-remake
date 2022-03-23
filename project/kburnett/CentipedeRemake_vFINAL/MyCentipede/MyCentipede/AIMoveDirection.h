#ifndef _AIMoveDirection
#define _AIMoveDirection

class Blaster;

class AIMoveDirection
{
public:
	AIMoveDirection() = default;
	AIMoveDirection(const AIMoveDirection&) = delete;
	AIMoveDirection& operator= (const AIMoveDirection&) = delete;
	~AIMoveDirection() = default;

	virtual void Move(Blaster* b) = 0;

private:
};

#endif _AIMoveDirection