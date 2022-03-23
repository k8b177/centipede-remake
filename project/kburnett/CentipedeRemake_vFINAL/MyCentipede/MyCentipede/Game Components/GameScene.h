// GameScene
// Katherine Burnett, September 2021

#ifndef _GameScene
#define _GameScene

#include "TEAL\CommonElements.h"
#include "../GameModeEnum.h"

class GameScene : public Scene
{
public:
	// Big Four
	GameScene() = default;
	GameScene(const GameScene&) = default;
	GameScene& operator= (const GameScene&) = default;
	~GameScene() = default;


	virtual void Initialize();
	virtual void Terminate();
};

#endif _GameScene