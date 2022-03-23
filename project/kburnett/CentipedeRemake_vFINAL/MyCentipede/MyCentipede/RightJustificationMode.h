// RightJustificationMode - Concrete Strategy for TextJustificationMode

#ifndef _RightJustificationMode
#define _RightJustificationMode

#include "TextJustificationMode.h"

class RightJustificationMode : public TextJustificationMode
{
public:
	// Big Four
	RightJustificationMode() = default;
	RightJustificationMode(const RightJustificationMode&) = delete;
	RightJustificationMode& operator=(const RightJustificationMode&) = delete;
	~RightJustificationMode() = default;

	std::list<Glyph*>* SetGlyphs(std::list<Glyph*>* glyphs, std::string s, sf::Vector2f startingPos, AwesomeFont* font) override;
	void PositionLeftTextBlock(int rowOrigin, int colOrigin, int strLen, SpriteString* s) override;
	void PositionRightTextBlock(int rowOrigin, int colOrigin, int strLen, SpriteString* s) override;
};

#endif _RightJustificationMode
