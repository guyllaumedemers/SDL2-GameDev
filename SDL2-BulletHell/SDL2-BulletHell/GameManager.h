#pragma once
#include <SDL.h>
#include <iostream>

class GameManager
{
public:
	static int onExecute();

private:
	static bool isRunning;

	//APP_LOGIC

	static void initialize();

	static void getInputs();

	static void runGameLogic();

	static void renderFrame();

	static void clear();

	//GAME_LOGIC
};

