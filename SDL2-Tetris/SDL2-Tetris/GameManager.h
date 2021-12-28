#pragma once
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <iostream>
#include "InputManager.h"
#include "Rendering.h"

class GameManager
{
private:

	static bool m_IsRunning;

	static void initialize();

	static void getInputs();

	static void runGameLogic();

	static void renderFrame();

	static void clear();

public:

	static void setIsRunning(const bool& value);

	static int onExecute();
};

