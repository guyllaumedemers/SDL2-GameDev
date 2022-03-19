#pragma once
#include "Window.h"
#include "Rendering.h"
#include "Timer.h"

using namespace std;
class GameManager
{
private:

	//FIELDS

	static bool isRunning;

	static Window* window;

	static Rendering* ren;

	static Timer* timer;

	//APP_LOGIC

	static void initialize();

	static void getInputs();

	static void runGameLogic();

	static void renderFrame();

	static void clear();

public:

	//GAME_LOGIC

	static int onExecute();
};

