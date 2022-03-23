#include "CenterJustificationMode.h"

#include "AwesomeFont.h"
#include "TextBlock.h"

#include "SpriteString.h"

std::list<Glyph*>* CenterJustificationMode::SetGlyphs(std::list<Glyph*>* glyphs, std::string s, sf::Vector2f startingPos, AwesomeFont* font)
{
	// Put middle character at origin
	int mid = (s.length() - 1) / 2; // get middle index
	int len = s.length();
	int i = mid; // set i to the middle index
	sf::Vector2f nextpos = startingPos; // set nextPos to origin
	glyphs->push_back(font->GetGlyph(s.at(i), startingPos));

	// Build characters to the left of the middle
	nextpos = startingPos;
	i -= 1; // subtract from i to get the index of the character to the left of the middle character
	nextpos.x -= font->CellWidth(); // subtract from nextPos to get the position to the left of the middle character
	for (i; i >= 0; i--)
	{
		glyphs->push_back(font->GetGlyph(s.at(i), nextpos));
		nextpos.x -= font->CellWidth();
	}

	// Build character to the right of the middle
	nextpos = startingPos; // Reset nextpos to the origin
	nextpos.x += font->CellWidth(); // add to nextPos to get the position to the right of the middle character
	i = mid + 1; // set i to the index of the character to the right of the middle character
	for (i; i < (int)s.length(); i++)
	{
		glyphs->push_back(font->GetGlyph(s.at(i), nextpos));
		nextpos.x += font->CellWidth();
	}


	return glyphs;
}

void CenterJustificationMode::PositionLeftTextBlock(int rowOrigin, int colOrigin, int strLen, SpriteString* s)
{
	int textBlockRow = rowOrigin;
	int textBlockCol = colOrigin - strLen / 2 + 1;
	
	s->GetLeftTextBlock()->SetRowCol(textBlockRow, textBlockCol);
}

void CenterJustificationMode::PositionRightTextBlock(int rowOrigin, int colOrigin, int strLen, SpriteString* s)
{
	int textBlockRow = rowOrigin;
	int textBlockCol = colOrigin + strLen / 2;

	s->GetRightTextBlock()->SetRowCol(textBlockRow, textBlockCol);
}