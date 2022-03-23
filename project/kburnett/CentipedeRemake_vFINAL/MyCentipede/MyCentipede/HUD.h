// HUD

#ifndef _HUD
#define _HUD

#include "Game Components/TEAL/CommonElements.h"
#include "AwesomeFont.h"

#include <list>


class HUD : GameObject //singleton
{
private:
	static HUD* ptrInstance;

	static HUD& Instance();

	HUD();
	HUD(const HUD&) = delete;
	HUD& operator= (const HUD&) = delete;
	~HUD() = default;


	AwesomeFont myfont;
	std::list<Glyph> ScoreSymbols;
	sf::Vector2f ScoreStartingPos;

	// private methods
	virtual void Draw();
	void privSetScoreSymbols(std::string scoreString);

public:
	static void SetScoreSymbols(std::string scoreString) { Instance().privSetScoreSymbols(scoreString); }

};



#endif _HUD

