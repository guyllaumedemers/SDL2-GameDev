#pragma once
#include <SDL.h>
#include <functional>
#include "TileMapGenerator.h"
#include "GameManager.h"
#include "Rendering.h"

typedef std::function<void(Uint8)> Action;

class InputManager
{
public:

	static void getInputEvent(SDL_Event& myEvent);
};

