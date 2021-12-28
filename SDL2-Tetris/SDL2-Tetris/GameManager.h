#pragma once
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <iostream>
#include "TileMapGenerator.h"
#include "InputManager.h"
#include "Rendering.h"
#include "Timer.h"
#include <vector>

#define GRIDWITDH 12
#define GRIDHEIGHT 24

#define TILESIZE 20
#define INTERVAL_IN_MS 1500

class GameManager
{
private:

	static bool m_IsRunning;

	static Timer* m_TetrominoeGenerationIntervalTimer;

	static Timer* m_TetrominoeTranslationIntervalTimer;

	static std::vector<Tetrominoe*> m_Tetrominoes;

	static void initialize();

	static void getInputs();

	static void runGameLogic();

	static void renderFrame();

	static void clear();

	static void generateTetrominoes();

	static int checkForCompleteAlignment(bool** map, const int& row, const int& col);

	static void updateTetrominoesPosition();

	static bool checkForCollision(const Tetrominoe& tetrominoe);

public:

	static void setIsRunning(const bool& value);

	static int onExecute();
};

