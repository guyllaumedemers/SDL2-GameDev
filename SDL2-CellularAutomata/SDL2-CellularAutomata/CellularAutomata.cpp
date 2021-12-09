#include "CellularAutomata.h"
#include "GameManager.h"
#include <iostream>

Point** CellularAutomata::s_NodeArr = nullptr;

int CellularAutomata::s_XOffset = 4;

int CellularAutomata::s_YOffset = 4;

int CellularAutomata::s_Population = 20;

void CellularAutomata::onInitialize(SDL_Renderer* ren)
{
	// initialize the 2d array with pointers
	s_NodeArr = new Point * [ROWS];

	for (int k = 0; k < ROWS; ++k) {
		s_NodeArr[k] = new Point[COLUMNS];
	}

	// initialize the values for each point with a random state
	for (int i = 0; i < ROWS; i += s_YOffset) {
		for (int j = 0; j < COLUMNS; j += s_XOffset) {

			s_NodeArr[i][j] = {
				new SDL_Rect{
					j,
					i,
					s_XOffset,
					s_YOffset
			},
				!(bool)(rand() % s_Population)
			};
		}
	}
}

void CellularAutomata::onUpdate(SDL_Renderer* ren)
{
	SDL_SetRenderDrawColor(ren, 0.0f, 0.0f, 0.0f, 0.0f);
	// clear the screen
	SDL_RenderClear(ren);
	// fill the color buffer
	SDL_SetRenderDrawColor(ren, 255.0f, 0.0f, 0.0f, 255.0f);
	// do the cellular automata rendering logic here
	for (int i = 0; i < ROWS; i += s_YOffset) {
		for (int j = 0; j < COLUMNS; j += s_XOffset) {

			if (s_NodeArr[i][j].m_isAlive) {

				SDL_RenderFillRect(ren, s_NodeArr[i][j].m_Rect);
			}
		}
	}
	// render the back buffer frame to the front buffer frame
	SDL_RenderPresent(ren);
}

void CellularAutomata::onClear()
{
	for (int i = 0; i < ROWS; ++i) {
		delete s_NodeArr[i];
	}
	delete s_NodeArr;
	s_NodeArr = nullptr;
}
