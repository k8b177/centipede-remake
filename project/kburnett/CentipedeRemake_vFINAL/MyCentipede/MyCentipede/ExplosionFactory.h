// ExplosionFactory

#ifndef _ExplosionFactory
#define _ExplosionFactory

#include "SFML/Graphics.hpp"
#include "ExplosionOneCellObjectPool.h"
#include "ExplosionTwoCellObjectPool.h"

class GameObject;

class ExplosionFactory // singleton
{
private:
	static ExplosionFactory* ptrInstance;

	ExplosionFactory();
	ExplosionFactory(const ExplosionFactory&) = delete;
	ExplosionFactory& operator=(const ExplosionFactory&) = delete;
	~ExplosionFactory() = default;

	static ExplosionFactory& Instance(); // Access reference

	ExplosionOneCellObjectPool myOneCellObjectPool;
	ExplosionTwoCellObjectPool myTwoCellObjectPool;

	// Private NON_STATIC methods to perform actual work on member var
	void privCreateOneCellExplosion(sf::Vector2f pos);
	void privCreateTwoCellExplosion(sf::Vector2f pos);
	void privRecycleOneCellExplosion(GameObject* e);
	void privRecycleTwoCellExplosion(GameObject* e);


public:
	static void CreateOneCellExplosion(sf::Vector2f pos)
	{
		Instance().privCreateOneCellExplosion(pos);
	};

	static void CreateTwoCellExplosion(sf::Vector2f pos)
	{
		Instance().privCreateTwoCellExplosion(pos);
	}

	static void RecycleOneCellExplosion(GameObject* e)
	{
		Instance().privRecycleOneCellExplosion(e);
	}

	static void RecycleTwoCellExplosion(GameObject* e)
	{
		Instance().privRecycleTwoCellExplosion(e);
	}

	static void Terminate();
};


#endif _SpiderFactory