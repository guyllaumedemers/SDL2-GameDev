#pragma once
#define SDL_MAIN_HANDLED
#include <SDL.h>

class GameManager
{
private:

	static bool isRunning;

	static SDL_Window* window;

	static SDL_Renderer* renderer;

	//APP_LOGIC

	static void initialize();

	static void getInputs();

	static void runGameLogic();

	static void renderFrame();

	static void clear();

public:

	static void setIsRunning(const bool& value);

	static int onExecute();
};

