#pragma once
#include <SDL.h>
#include <functional>
#include "TileMapGenerator.h"

typedef std::function<void(Uint8)> Action;

class InputManager
{
public:
	static void getInputEvent(SDL_Event& myEvent);

	static void doFlagCheck(const int& x, const int& y);

	static void uncoverTile(const int& x, const int& y);
};

