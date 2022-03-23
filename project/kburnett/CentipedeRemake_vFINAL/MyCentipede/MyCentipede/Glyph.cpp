// Glyph

#include "Glyph.h"
#include "SpriteSheet.h"
#include "Game Components/TEAL/WindowManager.h"

#include <assert.h>

Glyph::Glyph()
{
	sprsheet = nullptr;
	cellIndex = 0;
	position = sf::Vector2f(0, 0);
}

void Glyph::Initialize(SpriteSheet* sheet, int cellInd, sf::Vector2f pos)
{
	sprsheet = sheet;
	cellIndex = cellInd;
	position = pos;
}

void Glyph::Draw()
{
	assert(sprsheet != nullptr);

	sprsheet->Draw(cellIndex, position);
}

void Glyph::Reset()
{
	sprsheet = nullptr;
	cellIndex = 0;
	position = sf::Vector2f(0, 0);
}

void Glyph::Recycle()
{
	sprsheet->Recycle(this);
}
