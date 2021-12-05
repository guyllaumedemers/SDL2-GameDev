#pragma once
#include <SDL.h>
#include <functional>

typedef std::function<void(Uint8)> Action;

class InputManager
{
private:

public:
	static void getInputEvent(SDL_Event& myEvent);
};

