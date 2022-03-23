// AttractorScene
// Katherine Burnett, September 2021

#ifndef _AttractorScene
#define _AttractorScene

#include "Game Components/TEAL/CommonElements.h"


class AttractorScene : public Scene
{
public:
	// Big Four
	AttractorScene() = default;
	AttractorScene(const AttractorScene&) = default;
	AttractorScene& operator= (const AttractorScene&) = default;
	~AttractorScene() = default;


	virtual void Initialize();
	virtual void Terminate();
};

#endif _AtttractorScene