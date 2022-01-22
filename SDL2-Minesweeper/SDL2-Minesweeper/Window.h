#pragma once
#include <SDL.h>
#include <vector>
#include <iostream>
#include "Tile.h"
#include "PanelBuilder.h"
#include "MainPanelBuilder.h"

class Window
{
private:

	static int m_TopMenuBarHeight;

	static int m_GameContentInfoHeight;

	static SDL_Window* m_Window;

	static std::vector<Panel*> m_Panels;

	static PanelBuilder* m_PanelBuilder;

	static void initializeWindow(const int& x, const int& y, const int& width, const int& height);

	static SDL_Rect* initializeContentArea(const int& width, const int& height);

	static void addPanel(Panel* panel);

	static void removePanel(Panel* panel);

	static void resetBuilder();

	static void setBuilder(PanelBuilder* builder);

	static void destroyBuilder();

	static SDL_Rect* buildTopMenuPanel(const int& x, const int& y, const int& width, const int& height);

	static SDL_Rect* buildGameInfoPanel(const int& x, const int& y, const int& width, const int& height);

	static SDL_Rect* buildGamePanel(const int& x, const int& y, const int& width, const int& height);

public:

	static void intializeWindowCTX(const int& width, const int& height);

	static void setWindowSize(const int& x, const int& y);

	static SDL_Window* getWindow();

	static Panel* getPlayAreaPanel();
};

