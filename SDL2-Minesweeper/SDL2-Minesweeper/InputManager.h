#pragma once
#include "GameManager.h"

class InputManager
{
public:

	static void getInputEvent(SDL_Event& myEvent, Tile** map);
};