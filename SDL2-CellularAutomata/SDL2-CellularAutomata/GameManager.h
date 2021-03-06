#pragma once
#include <SDL.h>
#include <thread>
#include <chrono>

#define COLUMNS 640
#define ROWS 480
#define PIXELSIZE 4
#define PPC (COLUMNS/PIXELSIZE)
#define PPR (ROWS/PIXELSIZE)

class GameManager
{
private:

	static SDL_Window* m_Window;

	static SDL_Renderer* m_Renderer;

	static bool m_IsRunning;

private:

	static void onInitialize();

	static void onRun();

	static void onDraw();

	static void onClear();

public:

	static int onExecute();
};

