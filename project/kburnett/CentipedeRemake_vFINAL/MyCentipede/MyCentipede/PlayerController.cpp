#include "PlayerController.h"

#include "KeyboardControllerMode.h"
#include "AIControllerMode.h"
#include "FrozenControllerMode.h"

PlayerController::PlayerController()
	:CurrentControllerMode(nullptr)
{
	AIStrategy = new AIControllerMode();
	KeyboardStrategy = new KeyboardControllerMode();
	FrozenStrategy = new FrozenControllerMode();
}

void PlayerController::Update()
{
	CurrentControllerMode->MovementUpdate();
}

void PlayerController::SetCurrentControllerMode(ControllerMode* newControllerMode)
{
	CurrentControllerMode = newControllerMode;
}

PlayerController::~PlayerController()
{
	delete AIStrategy;
	delete KeyboardStrategy;
	delete FrozenStrategy;
}