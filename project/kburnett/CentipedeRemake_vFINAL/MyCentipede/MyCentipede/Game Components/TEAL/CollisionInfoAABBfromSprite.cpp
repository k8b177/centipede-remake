// CollisionInfoAABBfromSprite.h
// Andre Berthiaume, July 2012
// July 2019: memory clean up

#include "CollisionInfoAABBfromSprite.h"
#include "WindowManager.h"

sf::FloatRect CollisionInfoAABBfromSprite::getAABB(){ return sprite->getGlobalBounds(); }
sf::Vector2f CollisionInfoAABBfromSprite::getPosition(){ return sprite->getPosition(); }
float CollisionInfoAABBfromSprite::getRotation(){ return sprite->getRotation();}
sf::Transform CollisionInfoAABBfromSprite::getTransform(){ return sprite->getTransform(); }

void CollisionInfoAABBfromSprite::Draw(){ WindowManager::Window().draw( *sprite ); }