#pragma once
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <iostream>
#include "TileMapGenerator.h"
#include "InputManager.h"
#include "Rendering.h"
#include "Timer.h"

#define GRIDWITDH 12
#define GRIDHEIGHT 24

#define TILESIZE 20
#define INTERVAL_IN_MS 1500

class GameManager
{
private:

	static bool m_IsRunning;

	static Timer* m_Timer;

	static void initialize();

	static void getInputs();

	static void runGameLogic();

	static void renderFrame();

	static void clear();

	static void generateTetrominoes();

	static int checkForCompleteAlignment(bool** map);

public:

	static void setIsRunning(const bool& value);

	static int onExecute();
};

