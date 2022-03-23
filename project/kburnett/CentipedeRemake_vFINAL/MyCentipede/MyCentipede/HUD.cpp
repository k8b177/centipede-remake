// HUD

#include "HUD.h"

HUD* HUD::ptrInstance = nullptr;

HUD& HUD::Instance()
{
	if (!ptrInstance)
		ptrInstance = new HUD();
	return *ptrInstance;
}

HUD::HUD()
{
	ScoreStartingPos = sf::Vector2f(6 * myfont.CellWidth(), 0);
	
}

void HUD::Draw()
{
	std::list<Glyph>::iterator it;
	for (it = ScoreSymbols.begin(); it != ScoreSymbols.end(); it++)
		it->Draw();
}

void HUD::privSetScoreSymbols(std::string scoreString)
{
	/*
	sf::Vector2f nextpos = ScoreStartingPos;
	int i = scoreString.length() - 1;
	for (i; i >= 0; i--)
	{
		ScoreSymbols.push_back(myfont.GetGlyph(scoreString.at(i), nextpos));
		nextpos.x -= myfont.CellWidth();
	}
	*/
}