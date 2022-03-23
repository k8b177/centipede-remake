// Keyboard_PlayerController
// Katherine Burnett, September 2021

#include "Keyboard_PlayerController.h"


Keyboard_PlayerController::Keyboard_PlayerController(Blaster* blaster)
{
	LEFT = sf::Keyboard::Key::Left;
	RIGHT = sf::Keyboard::Key::Right;
	UP = sf::Keyboard::Key::Up;
	DOWN = sf::Keyboard::Key::Down;
	FIRE = sf::Keyboard::Key::S;
	
	this->blaster = blaster;
}
Keyboard_PlayerController::~Keyboard_PlayerController()
{

}

void Keyboard_PlayerController::Update()
{
	if (sf::Keyboard::isKeyPressed(LEFT)) blaster->MoveLeft();
	if (sf::Keyboard::isKeyPressed(RIGHT)) blaster->MoveRight();
	if (sf::Keyboard::isKeyPressed(UP)) blaster->MoveUp();
	if (sf::Keyboard::isKeyPressed(DOWN)) blaster->MoveDown();
	if (sf::Keyboard::isKeyPressed(FIRE)) blaster->Fire();
}