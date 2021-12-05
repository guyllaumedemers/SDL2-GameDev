#pragma once
#include <SDL.h>
#include <functional>

typedef std::function<void(Uint8)> Action;

class InputManager
{
public:
	static void getInputEvent(SDL_Event& myEvent);

	static void getMouseClickPos(unsigned short int& x, unsigned short int& y);
};

