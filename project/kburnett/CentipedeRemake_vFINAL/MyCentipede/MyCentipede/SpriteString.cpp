#include "SpriteString.h"

#include "Glyph.h"
#include "TextJustificationMode.h"

#include "TextBlock.h"

SpriteString::SpriteString(TextJustificationMode* textJustification, int row, int col, sf::Vector2f origin, AwesomeFont* font, bool isBlocking)
	:myTextJustification(textJustification), row(row), col(col), myOrigin(origin), myFont(font)
{
	RightTextBlock = new TextBlock();
	LeftTextBlock = new TextBlock();
}

TextBlock* SpriteString::GetRightTextBlock()
{
	return RightTextBlock;
}
TextBlock* SpriteString::GetLeftTextBlock()
{
	return LeftTextBlock;
}

void SpriteString::SetGlyphList(std::string s)
{
	ClearGlyphList();
	myTextJustification->SetGlyphs(&GlyphList, s, myOrigin, myFont);
}

void SpriteString::PositionTextBlocks()
{
	myTextJustification->PositionLeftTextBlock(row, col, GlyphList.size(), this);
	myTextJustification->PositionRightTextBlock(row, col, GlyphList.size(), this);
}

void SpriteString::ClearGlyphList()
{
	for (Glyph* g : GlyphList)
	{
		g->Recycle();
	}
	GlyphList.clear();
}

void SpriteString::Draw()
{
	for (Glyph* g : GlyphList)
	{
		g->Draw();
	}
}

SpriteString::~SpriteString()
{
	delete RightTextBlock;
	delete LeftTextBlock;
	ClearGlyphList();
}