#pragma once
#pragma once
#include <SDL.h>
#include <vector>
#include <iostream>
#include "Tile.h"
#include "Rendering.h"
#include "PanelBuilder.h"
#include "MainPanelBuilder.h"
#include "SubPanelBuilder.h"

class Window
{
private:

	static int m_TopMenuBarHeight;

	static int m_GameContentInfoHeight;

	static SDL_Window* m_Window;

	static std::vector<Panel*> m_Panels;

	static PanelBuilder* m_PanelBuilder;

	static SDL_Rect* initializeContentArea(const int& width, const int& height);

	static void addPanel(Panel* panel);

	static void removePanel(Panel* panel);

	//BUILDER_LOGIC

	static void resetBuilder();

	static void setBuilder(PanelBuilder* builder);

	static void destroyBuilder();

	//MAIN_UI_GENERATION_LOGIC

	static SDL_Rect* buildTopMenuPanel(const int& x, const int& y, const int& width, const int& height);

	static SDL_Rect* buildGameInfoPanel(const int& x, const int& y, const int& width, const int& height);

	static SDL_Rect* buildGamePanel(const int& x, const int& y, const int& width, const int& height);

	//SUB_UI_GENERATION_LOGIC

	static SDL_Rect* buildSubPanel(Panel* panel, const int& x, const int& y, const int& width, const int& height, SDL_Texture* texture);

	//RESET_PANELS

	static void resetPanels();

	static int getNextPanelHeightPosition(SDL_Rect* rect);

	static int getNextPanelWidthPosition(SDL_Rect* rect);

public:

	//APP_LOGIC

	static void initializeWindow(const int& x, const int& y, const int& width, const int& height);

	static void setWindowSize(const int& width, const int& height);

	static SDL_Window* getWindow();

	static std::vector<Panel*> getPanels();

	static Panel* getPlayAreaPanel();
};

