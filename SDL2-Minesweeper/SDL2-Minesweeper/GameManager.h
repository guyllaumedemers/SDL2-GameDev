#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <functional>
#include "Timer.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

// Hint :	SDL_Surface is use for software rendering *CPU and is stored in system RAM which is less efficient than using the GPU
//			while SDL_Texture is use for hardware rendering *GPU and is store in the GPU Ram

class GameManager
{
private:

	static bool m_IsRunning;

	static SDL_Window* m_Window;

	static SDL_Renderer* m_Renderer;

	static SDL_Surface* m_SurfaceDisplay;

	static SDL_Surface* m_ImgSurfaceDisplay;

	static SDL_Texture* m_Texture;

	static Timer* m_Timer;

	static void initializeGame();

	static void getInputEvents();

	static void runGameLogic();

	static void renderFrame();

	static void clear();

public:

	static void setIsRunning(const bool& value);

	static int onExecute();
};

