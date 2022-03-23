// TextJustificationMode - Strategy Base 

#ifndef _TextJustificationMode
#define _TextJustificationMode

#include "SFML/Window.hpp"
#include <list>

class Glyph;
class AwesomeFont;
struct TextBlock;
class SpriteString;

class TextJustificationMode
{
public:
	// Big Four
	TextJustificationMode() = default;
	TextJustificationMode(const TextJustificationMode&) = delete;
	TextJustificationMode& operator=(const TextJustificationMode&) = delete;
	~TextJustificationMode() = default;

	virtual std::list<Glyph*>* SetGlyphs(std::list<Glyph*>* glyphs, std::string s, sf::Vector2f startingPos, AwesomeFont* font) = 0;
	virtual void PositionLeftTextBlock(int rowOrigin, int colOrigin, int strLen, SpriteString* s) = 0;
	virtual void PositionRightTextBlock(int rowOrigin, int colOrigin, int strLen, SpriteString* s) = 0;
};

#endif _TextJustificationMode
