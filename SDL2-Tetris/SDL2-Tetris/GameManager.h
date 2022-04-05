#pragma once
#include "Window.h"
#include "Renderer.h"
#include "Difficulty.h"

class GameManager
{
private:

	//FIELDS

	static bool isRunning;

	static Window* window;

	static Renderer* ren;

	static Difficulty* mode;

	//APP_LOGIC

	static void initialize();

	static void getInputs();

	static void runGameLogic();

	static void renderFrame();

	static void clear();

public:

	//APP_LOGIC

	static int onExecute();

	static void setIsRunning(bool);
};

