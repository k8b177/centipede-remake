#include "RightJustificationMode.h"

#include "AwesomeFont.h"

std::list<Glyph*>* RightJustificationMode::SetGlyphs(std::list<Glyph*>* glyphs, std::string s, sf::Vector2f startingPos, AwesomeFont* font)
{
	sf::Vector2f nextpos = startingPos;
	int i = s.length() - 1;
	for (i; i >= 0; i--)
	{
		glyphs->push_back(font->GetGlyph(s.at(i), nextpos));
		nextpos.x -= font->CellWidth();
	}

	return glyphs;
}

void RightJustificationMode::PositionLeftTextBlock(int rowOrigin, int colOrigin, int strLen, SpriteString* s)
{

}

void RightJustificationMode::PositionRightTextBlock(int rowOrigin, int colOrigin, int strLen, SpriteString* s)
{

}