#ifndef _SpriteString
#define _SpriteString

#include "Game Components/TEAL/CommonElements.h"
#include "TextJustificationEnum.h"
#include <list>

class Glyph;
class TextJustificationMode;
class AwesomeFont;
struct TextBlock;

class SpriteString
{
public:
	// Big Four
	SpriteString() = delete;
	SpriteString(const SpriteString&) = delete;
	SpriteString& operator=(const SpriteString&) = delete;
	~SpriteString();

	SpriteString(TextJustificationMode* textJustification, int row, int col, sf::Vector2f origin, AwesomeFont* font, bool isBlocking);

	void SetGlyphList(std::string s);
	void PositionTextBlocks();
	void ClearGlyphList();

	void Draw();

	TextBlock* GetRightTextBlock();
	TextBlock* GetLeftTextBlock();


private:
	TextJustificationMode* myTextJustification;
	sf::Vector2f myOrigin;
	std::list<Glyph*> GlyphList;
	AwesomeFont* myFont;


	int row;
	int col;


	TextBlock* RightTextBlock;
	TextBlock* LeftTextBlock;

};


#endif _SpriteString

