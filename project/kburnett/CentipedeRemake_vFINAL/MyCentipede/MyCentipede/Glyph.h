// Glyph

#ifndef _Glyph
#define _Glyph

#include "SFML\Graphics.hpp"

class SpriteSheet; // forward declaration

class Glyph
{
public:
	Glyph();
	Glyph(const Glyph&) = delete;
	Glyph& operator=(const Glyph&) = delete;
	~Glyph() = default;

	void Draw();

	void Initialize(SpriteSheet* sheet, int cellInd, sf::Vector2f pos);
	void Reset();
	void Recycle();

private:
	SpriteSheet* sprsheet;
	int cellIndex;
	sf::Vector2f position;

};


#endif _Glyph