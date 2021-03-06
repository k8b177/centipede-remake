// TEALShow.cpp
// Andre Berthiaume, June 2012
// July 2019: memory clean up
//
// Debugging tool to easily visualize graphical elements
//

#include "TEALShow.h"
#include "WindowManager.h"
#include "ConsoleMsg.h"
#include "Tools.h"

using namespace std;

TEALShow* TEALShow::TSInstance = NULL;

//sf::Font TEALShow::DefaultFont;
//sf::Text TEALShow::Monitor;
//std::string TEALShow::Message;
//sf::Color TEALShow::MonitorCol = sf::Color::White;
//
//const int TEALShow::MAXCOUNT = 5000;
//
//sf::Vertex TEALShow::Lines[MAXCOUNT];
//int TEALShow::linecount = 0;
//
//std::list<TEALShow::Linestrip> TEALShow::LinestripList;
//
//sf::Shape* TEALShow::ShapeList[MAXCOUNT];
//int TEALShow::shapecount = 0;
//
//list<sf::Text> TEALShow::LabelList;

TEALShow::TEALShow()
{
	if ( ! DefaultFont.loadFromFile("Game Components/TEAL/arial.ttf"))
		ConsoleMsg::ShowError("TEALSHOW Failed to load default font");

	Monitor.setFont( DefaultFont );
	Monitor.setString("");
	Monitor.setCharacterSize(16);
}

void TEALShow::Text( std::string msg )
{
	Instance();
	Instance().Message += msg + "\n";
}

void TEALShow::Draw()
{
	// Draw lines
	WindowManager::Window().draw(Instance().Lines, Instance().linecount, sf::Lines);
	//Text("linecount = " + Tools::ToString(linecount / 2));
	Instance().linecount = 0;

	// Draw shapes
	for (int i=0; i < Instance().shapecount; i++)
	{
		WindowManager::Window().draw( *Instance().ShapeList[i] );
		delete Instance().ShapeList[i];
	}
	Instance().shapecount = 0;
	
	// Draw Text
	Instance().Monitor.setString(Instance().Message );
	Instance().Monitor.setFillColor(Instance().MonitorCol );
	WindowManager::Window().draw(Instance().Monitor );
	Instance().Message = "";

	// Draw linestrips
	std::list<TEALShow::Linestrip>::const_iterator it;
	for (it = Instance().LinestripList.begin(); it != Instance().LinestripList.end(); it++)
		WindowManager::Window().draw( &(it->points[0]), it->size, sf::LinesStrip);
	Instance().LinestripList.clear();

	// Draw label
	std::list<sf::Text>::iterator lit;
	for( lit = Instance().LabelList.begin(); lit != Instance().LabelList.end(); lit++)
		WindowManager::Window().draw( *lit);
	Instance().LabelList.clear();

}

void TEALShow::Line( sf::Vector2f p1, sf::Vector2f p2, sf::Color c)
{
	if (MAXCOUNT- Instance().linecount < 2)
		ConsoleMsg::ShowError("Too many lines drawn in TEALShow... Max currently set at " + Tools::ToString(Instance().linecount) + " lines." );
	
	Instance().Lines[Instance().linecount].position = p1;
	Instance().Lines[Instance().linecount].color = c;
	Instance().Lines[Instance().linecount+1].position = p2;
	Instance().Lines[Instance().linecount+1].color = c;
	Instance().linecount += 2;
}

void TEALShow::Mark( sf::Vector2f p, sf::Color col, float radius )
{
	sf::Vector2f offset(radius, radius);
	Line( p-offset, p+offset, col);
	offset.y *= -1;
	Line( p-offset, p+offset, col);
}
	
void TEALShow::Dot( sf::Vector2f p, sf::Color col, float radius )
{
	if (MAXCOUNT- Instance().shapecount < 1) ConsoleMsg::ShowError("Too many shapes drawn with TEALShow...");

	Instance().ShapeList[Instance().shapecount] = new sf::CircleShape(radius, 12);
	Instance().ShapeList[Instance().shapecount]->setOrigin(radius,radius);
	Instance().ShapeList[Instance().shapecount]->setPosition(p);
	Instance().ShapeList[Instance().shapecount]->setFillColor(col);

	Instance().shapecount++;
}

void TEALShow::Circle( sf::Vector2f center, float radius, sf::Color col)
{
	// Get a dummy CircleShape just to get the points from it
	sf::CircleShape c(radius,24);
	c.setOrigin( radius, radius);
	c.setPosition( center );

	// Fill up the LInestrip details
	Linestrip strip;
	strip.size = c.getPointCount() + 1;
	strip.points.resize( strip.size);
	for(int i=0; i < (int) c.getPointCount(); i++)
	{
		strip.points[i].position = c.getTransform().transformPoint( c.getPoint(i) );
		strip.points[i].color = col;
	}
	strip.points[c.getPointCount()] = strip.points[0];

	Instance().LinestripList.push_back( strip);

}

void TEALShow::AddTransformedRectanglePoints( sf::FloatRect r, sf::Transform T, sf::Color col )
{
	Linestrip strip;
	strip.size = 5;
	strip.points.resize(strip.size); 
	strip.points[0].position = T.transformPoint( sf::Vector2f( r.left, r.top) );
	strip.points[0].color = col;
	strip.points[1].position = T.transformPoint( sf::Vector2f(r.left + r.width,  r.top ) );
	strip.points[1].color = col;
	strip.points[2].position = T.transformPoint( sf::Vector2f( r.left + r.width, r.top + r.height ));
	strip.points[2].color = col;
	strip.points[3].position = T.transformPoint( sf::Vector2f( r.left, r.top + r.height ) );
	strip.points[3].color = col;
	strip.points[4] = strip.points[0];

	LinestripList.push_back( strip);
}

void TEALShow::Box( sf::FloatRect r, sf::Color col)
{
	Instance().AddTransformedRectanglePoints( r, sf::Transform(), col);
}

void TEALShow::Box( sf::FloatRect r, sf::Transform T, sf::Color col)
{
	Instance().AddTransformedRectanglePoints( r, T, col);
}

void TEALShow::AABB( sf::Shape &s, sf::Color col)
{
	Box( s.getGlobalBounds(), col);
}

void TEALShow::AABB( sf::Sprite &s, sf::Color col)
{
	Box( s.getGlobalBounds(), col);
}

void TEALShow::OrientedBox( sf::Sprite &s, sf::Color col)
{
	Instance().AddTransformedRectanglePoints( s.getLocalBounds(), s.getTransform(), col );
}

void TEALShow::OrientedBox( sf::Shape &s, sf::Color col)
{
	Instance().AddTransformedRectanglePoints( s.getLocalBounds(), s.getTransform(), col );
}

void TEALShow::Label( std::string label, sf::Vector2f pos, sf::Color col )
{
	Instance();

	sf::Text LabelTxt(label, Instance().DefaultFont, 12);
	LabelTxt.setOrigin( 0.5f * sf::Vector2f(LabelTxt.getLocalBounds().width, LabelTxt.getLocalBounds().height)  );
	LabelTxt.setPosition(pos);
	LabelTxt.setFillColor(col);
	Instance().LabelList.push_back(LabelTxt);
}

void TEALShow::Terminate()
{
	delete Instance().TSInstance;
}