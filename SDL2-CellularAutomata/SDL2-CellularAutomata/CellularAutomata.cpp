#include "CellularAutomata.h"
#include "GameManager.h"
#include <iostream>

Point CellularAutomata::s_NodeArr[PPR][PPC];

bool CellularAutomata::s_BoolArr[PPR][PPC] = { {false} };

int CellularAutomata::s_RandomnessFactor = 2;

void CellularAutomata::onInitialize(SDL_Renderer* ren)
{
	if (s_NodeArr == nullptr) {
		SDL_Log("Point Arrray is not initialized : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	else if (s_BoolArr == nullptr) {
		SDL_Log("Bool Arrray is not initialized : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	int x, y = 0;
	Point* temp = &s_NodeArr[0][0];

	for (int i = 0; i < PPR; ++i) {
		for (int j = 0; j < PPC; ++j) {
			x = j * PIXELSIZE;
			y = i * PIXELSIZE;

			(*temp).m_Rect = new SDL_Rect{
				x,
				y,
				PIXELSIZE,
				PIXELSIZE
			};
			(*temp).m_isAlive = rand() % s_RandomnessFactor;
			++temp;
		};
	}
	temp = nullptr;
	delete temp;
}

void CellularAutomata::onUpdate(SDL_Renderer* ren)
{
	// update the neighbors values
	onNeighborsUpdate();
	// do the cellular automata rendering logic here
	onRender(ren);
}

void CellularAutomata::onNeighborsUpdate()
{
	bool* result = nullptr;
	Point* temp = nullptr;

	int count = 0;

	for (int i = 1; i < PPR - 1; ++i) {
		for (int j = 1; j < PPC - 1; ++j) {

			result = &s_BoolArr[i][j];
			temp = &s_NodeArr[i][j];

			count =
				s_NodeArr[i - 1][j].m_isAlive +
				s_NodeArr[i + 1][j].m_isAlive +
				s_NodeArr[i - 1][j - 1].m_isAlive +
				s_NodeArr[i - 1][j + 1].m_isAlive +
				s_NodeArr[i][j - 1].m_isAlive +
				s_NodeArr[i][j + 1].m_isAlive +
				s_NodeArr[i + 1][j - 1].m_isAlive +
				s_NodeArr[i + 1][j + 1].m_isAlive;

			if ((*temp).m_isAlive) {
				(*result) = (count == 2 || count == 3);
			}
			else {
				(*result) = (count == 3);
			}
		}
	}
	result = nullptr;
	delete result;
	temp = nullptr;
	delete temp;
}

void CellularAutomata::onRender(SDL_Renderer* ren)
{
	bool* result = &s_BoolArr[0][0];
	Point* temp = &s_NodeArr[0][0];

	for (int i = 0; i < PPR; ++i) {
		for (int j = 0; j < PPC; ++j) {

			if ((*result)) {
				SDL_RenderFillRect(ren, (*temp).m_Rect);
			}
			(*temp).m_isAlive = (*result);
			++result;
			++temp;
		}
	}
	result = nullptr;
	delete result;
	temp = nullptr;
	delete temp;
}
