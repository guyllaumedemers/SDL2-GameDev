#pragma once
#include <SDL.h>

#define COLUMNS 640
#define ROWS 480

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

