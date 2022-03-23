// BlasterSpawner


#ifndef  _BlasterSpawner
#define _BlasterSpawner

class BlasterSpawner
{
public:
	// Big Four
	BlasterSpawner();
	BlasterSpawner(const BlasterSpawner&) = delete;
	BlasterSpawner& operator=(const BlasterSpawner&) = delete;
	~BlasterSpawner();

	void SpawnBlaster();
	void ResetBlasterPos();

private:
};

#endif _BlasterSpawner
