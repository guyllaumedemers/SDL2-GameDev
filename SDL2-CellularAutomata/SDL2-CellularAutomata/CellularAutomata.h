#pragma once
#pragma once
#include <SDL.h>
#include "GameManager.h"

struct Point {
	SDL_Rect* m_Rect;
	bool m_isAlive;

	Point() {
		m_Rect = nullptr;
		m_isAlive = false;
	}
	~Point() {
		delete m_Rect;
	}
};

class CellularAutomata
{
private:

	static Point s_NodeArr[][PPC];

	static bool s_BoolArr[][PPC];

	static int s_RandomnessFactor;

public:

	static void onInitialize(SDL_Renderer* ren);

	static void onUpdate(SDL_Renderer* ren);

	static void onNeighborsUpdate();

	static void onRender(SDL_Renderer* ren);
};

