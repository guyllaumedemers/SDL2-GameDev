#pragma once
#include <SDL.h>
#include "Window.h"
#include "Rendering.h"

class GameManager
{
public:
	static int onExecute();

private:
	static bool isRunning;

	static Window* window;

	static Rendering* ren;

	//APP_LOGIC

	static void initialize();

	static void getInputs();

	static void runGameLogic();

	static void renderFrame();

	static void clear();

	//GAME_LOGIC
};

