#include "GameConstants.h"

float GameConstants::VOLUME = 5.0f;

float GameConstants::CENTIPEDETURN_ANGLEINCREMENT = 180.0f / CELLSIZE;

float GameConstants::WINDOWSIZE_X = WindowManager::Window().getView().getSize().x;
float GameConstants::WINDOWSIZE_Y = WindowManager::Window().getView().getSize().x;

float GameConstants::TIME_BEFORE_HEADS_IN_PLAYER_AREA_SPAWN = 10.0f;
float GameConstants::TIME_BETWEEN_CENTIPEDE_HEAD_SPAWNING = 7.0f;