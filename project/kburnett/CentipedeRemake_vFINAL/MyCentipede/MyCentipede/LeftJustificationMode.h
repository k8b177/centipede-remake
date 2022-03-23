// LeftJustificationMode - Concrete Strategy for TextJustificationMode

#ifndef _LeftJustificationMode
#define _LeftJustificationMode

#include "TextJustificationMode.h"

class LeftJustificationMode : public TextJustificationMode
{
public:
	// Big Four
	LeftJustificationMode() = default;
	LeftJustificationMode(const LeftJustificationMode&) = delete;
	LeftJustificationMode& operator=(const LeftJustificationMode&) = delete;
	~LeftJustificationMode() = default;

	std::list<Glyph*>* SetGlyphs(std::list<Glyph*>* glyphs, std::string s, sf::Vector2f startingPos, AwesomeFont* font) override;
	void PositionLeftTextBlock(int rowOrigin, int colOrigin, int strLen, SpriteString* s) override;
	void PositionRightTextBlock(int rowOrigin, int colOrigin, int strLen, SpriteString* s) override;
};

#endif _LeftJustificationMode
