#pragma once
#include "Debugger.h"
#include "Window.h"
#include "Rendering.h"
#include "Ring.h"

class GameManager
{
private:

	//FIELDS

	static bool isRunning;

	static Window* window;

	static Rendering* ren;

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

