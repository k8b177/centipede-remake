// ExplosionOneCellFactory

#ifndef _ExplosionOneCellFactory
#define _ExplosionOneCellFactory

#include "SFML/Graphics.hpp"
#include "ExplosionOneCellObjectPool.h"

class GameObject;


class ExplosionOneCellFactory // singleton
{
private:
	static ExplosionOneCellFactory* ptrInstance;

	ExplosionOneCellFactory();
	ExplosionOneCellFactory(const ExplosionOneCellFactory&) = delete;
	ExplosionOneCellFactory& operator=(const ExplosionOneCellFactory&) = delete;
	~ExplosionOneCellFactory() = default;

	static ExplosionOneCellFactory& Instance(); // Access reference

	ExplosionOneCellObjectPool myObjectPool;

	// Private NON_STATIC methods to perform actual work on member var
	void privCreateOneCellExplosion(sf::Vector2f pos);
	void privRecycleOneCellExplosion(GameObject* e);


public:
	static void CreateOneCellExplosion(sf::Vector2f pos)
	{
		Instance().privCreateOneCellExplosion(pos);
	};

	static void RecycleOneCellExplosion(GameObject* e)
	{
		Instance().privRecycleOneCellExplosion(e);
	}

	static void Terminate();
};


#endif _SpiderFactory