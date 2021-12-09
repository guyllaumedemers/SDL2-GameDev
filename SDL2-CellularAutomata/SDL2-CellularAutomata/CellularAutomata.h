#pragma once
#include <SDL.h>

struct Point {
	SDL_Rect* m_Rect;
	bool m_isAlive;
};

class CellularAutomata
{
private:

	static Point** s_NodeArr;

	static bool** s_StateArr;

	static int s_XOffset;

	static int s_YOffset;

	static int s_Population;

public:

	static void onInitialize(SDL_Renderer* ren);

	static void onUpdate(SDL_Renderer* ren);

	static void onNeighborsUpdate();

	static void onRender(SDL_Renderer* ren);

	static void onClear();
};

