// CenterJustificationMode - Concrete Strategy for TextJustificationMode

#ifndef _CenterJustificationMode
#define _CenterJustificationMode

#include "TextJustificationMode.h"

class CenterJustificationMode : public TextJustificationMode
{
public:
	// Big Four
	CenterJustificationMode() = default;
	CenterJustificationMode(const CenterJustificationMode&) = delete;
	CenterJustificationMode& operator=(const CenterJustificationMode&) = delete;
	~CenterJustificationMode() = default;

	std::list<Glyph*>* SetGlyphs(std::list<Glyph*>* glyphs, std::string s, sf::Vector2f startingPos, AwesomeFont* font) override;
	void PositionLeftTextBlock(int rowOrigin, int colOrigin, int strLen, SpriteString* s) override;
	void PositionRightTextBlock(int rowOrigin, int colOrigin, int strLen, SpriteString* s) override;
};

#endif _CenterJustificationMode
