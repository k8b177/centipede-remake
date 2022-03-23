// GlyphFactory

#ifndef _GlyphFactory
#define _GlyphFactory

#include "SFML\Graphics.hpp"
#include "GlyphObjectPool.h"

class SpriteSheet;
class Glyph;

class GlyphFactory
{
public:
	GlyphFactory() = default;
	GlyphFactory(const GlyphFactory&) = delete;
	GlyphFactory& operator=(const GlyphFactory&) = delete;
	~GlyphFactory() = default;

	Glyph* CreateGlyph(SpriteSheet* sheet, int cellInd, sf::Vector2f pos);
	void RecycleGlyph(Glyph* g);

private:
	GlyphObjectPool myObjectPool;

};


#endif _Glyph