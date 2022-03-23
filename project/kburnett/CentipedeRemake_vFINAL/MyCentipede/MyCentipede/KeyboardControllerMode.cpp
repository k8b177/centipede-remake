#include "KeyboardControllerMode.h"

#include "BlasterFactory.h"
#include "Blaster.h"

KeyboardControllerMode::KeyboardControllerMode()
{
	LEFT = sf::Keyboard::Key::Left;
	RIGHT = sf::Keyboard::Key::Right;
	UP = sf::Keyboard::Key::Up;
	DOWN = sf::Keyboard::Key::Down;
	FIRE = sf::Keyboard::Key::S;

	blaster = BlasterFactory::GetBlaster();
}

void KeyboardControllerMode::MovementUpdate()
{
	if (sf::Keyboard::isKeyPressed(LEFT)) blaster->MoveLeft();
	if (sf::Keyboard::isKeyPressed(RIGHT)) blaster->MoveRight();
	if (sf::Keyboard::isKeyPressed(UP)) blaster->MoveUp();
	if (sf::Keyboard::isKeyPressed(DOWN)) blaster->MoveDown();
	if (sf::Keyboard::isKeyPressed(FIRE)) blaster->Fire();
}