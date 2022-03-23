#include "GlyphFactory.h"
#include "Glyph.h"

Glyph* GlyphFactory::CreateGlyph(SpriteSheet* sheet, int cellInd, sf::Vector2f pos)
{
	Glyph* g = myObjectPool.GetGlyph();
	g->Initialize(sheet, cellInd, pos);

	return g;
}

void GlyphFactory::RecycleGlyph(Glyph* g)
{
	myObjectPool.ReturnGlyph(g);
}