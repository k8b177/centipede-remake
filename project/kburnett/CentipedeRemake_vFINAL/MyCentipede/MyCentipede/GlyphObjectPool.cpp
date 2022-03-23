#include "GlyphObjectPool.h"

#include "Glyph.h"

GlyphObjectPool::GlyphObjectPool()
{

}

GlyphObjectPool::~GlyphObjectPool()
{
	// forcefully delete all recycled gameobjects

	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Glyph* GlyphObjectPool::GetGlyph()
{
	Glyph* g;

	if (recycledItems.empty())
	{
		g = new Glyph();
	}
	else
	{
		g = recycledItems.top();
		recycledItems.pop();	// Remember: top doesn't pop and pop returns void...

		// Tell the object to register itself to the scene
		//g->RegisterToCurrentScene();
	}

	return g;
}

void GlyphObjectPool::ReturnGlyph(Glyph* g)
{
	g->Reset();
	recycledItems.push(static_cast<Glyph*>(g));
}