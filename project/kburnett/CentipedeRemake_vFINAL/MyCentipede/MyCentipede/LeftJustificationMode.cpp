#include "LeftJustificationMode.h"

#include "AwesomeFont.h"

#include "Game Components/TEAL/CommonElements.h"

std::list<Glyph*>* LeftJustificationMode::SetGlyphs(std::list<Glyph*>* glyphs, std::string s, sf::Vector2f startingPos, AwesomeFont* font)
{
	int len = s.length();

	if (len != 0)
	{
		sf::Vector2f nextpos = startingPos;
		int i = 0;

		for (i; i <= len - 1; i++)
		{
			glyphs->push_back(font->GetGlyph(s.at(i), nextpos));
			nextpos.x += font->CellWidth();
		}
	}

	return glyphs;
}

void LeftJustificationMode::PositionLeftTextBlock(int rowOrigin, int colOrigin, int strLen, SpriteString* s)
{

}

void LeftJustificationMode::PositionRightTextBlock(int rowOrigin, int colOrigin, int strLen, SpriteString* s)
{

}