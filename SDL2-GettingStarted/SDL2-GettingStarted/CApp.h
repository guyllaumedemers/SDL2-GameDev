#pragma once

#include <SDL.h>
#include <SDL_image.h>
#undef main
#include <iostream>
#include <vector>
#include "CEvent.h"
#include "CSurface.h"

#define WIDTH 600
#define HEIGHT 600
#define ROW 3
#define COL 3
#define FILES 3

class CApp : public CEvent
{
private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* ren;

	std::vector<CSurface> surfaces;
	int Grid[9];

	bool fplayer;
	int counter;

	enum {
		GRID_TYPE_NONE = 0,
		GRID_TYPE_X,
		GRID_TYPE_O
	};

private:
	bool OnInit();						// This function handles all the loading of data, whether it be textures, maps, NPCs, or whatever.

	void OnEvent(SDL_Event* event);		// This function handles all input events from the mouse, keyboard, joysticks, or other devices.

	void OnLoop();						// This function handles all the data updates, such as a NPCs moving across the screen, decreasing your health bar, or whatever

	void OnRender();					// This function handles all the rendering of anything that shows up on the screen. It does NOT handle data manipulation, as this is what the Loop function is supposed to handle.

	void OnCleanup();					// This function simply cleans up any resources loaded, and insures a peaceful quitting of the game.

public:
	// Constructor
	CApp();
	// Destructor
	~CApp();
	// Functions
	int OnExecute();

private:
	void CheckGameStatus();

	void PopupMsg(const std::string& result);

	bool HasCompleteRow(int type);

	bool HasCompleteColumn(int type);

	bool HasCompleteDiagonal(int type);

	void ResetGame();

public:
	// Function Override
	void OnExit();

	void OnLButtonDown(uint16_t mX, uint16_t mY);
};