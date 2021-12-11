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

	int x, y = 0;
	Point* temp = &s_NodeArr[0][0];

	for (int i = 0; i < (PPR * PIXELSIZE); i += PIXELSIZE) {
		for (int j = 0; j < (PPC * PIXELSIZE); j += PIXELSIZE) {
			x = j;
			y = i;

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
	Point* temp = &s_NodeArr[PIXELSIZE][PIXELSIZE];

	bool* result = &s_BoolArr[PIXELSIZE][PIXELSIZE];
	int count = 0;

	for (int i = PIXELSIZE; i < ((PPR * PIXELSIZE) - PIXELSIZE); i += PIXELSIZE) {
		for (int j = PIXELSIZE; j < ((PPC * PIXELSIZE) - PIXELSIZE); j += PIXELSIZE) {

			count =
				(*(temp + sizeof(Point))).m_isAlive +
				(*(temp - sizeof(Point))).m_isAlive +
				(*(temp + (PPR * sizeof(Point)))).m_isAlive +
				(*(temp - (PPR * sizeof(Point)))).m_isAlive +
				(*(temp + ((PPR * sizeof(Point))) + sizeof(Point))).m_isAlive +
				(*(temp + ((PPR * sizeof(Point))) - sizeof(Point))).m_isAlive +
				(*(temp - ((PPR * sizeof(Point))) + sizeof(Point))).m_isAlive +
				(*(temp - ((PPR * sizeof(Point))) - sizeof(Point))).m_isAlive;
			//std::cout << count << std::endl;
			if ((*temp).m_isAlive) {
				(*result) = (count == 2 || count == 3);
			}
			else {
				(*result) = (count == 3);
			}
			++temp;
			++result;
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

	for (int i = 0; i < (PPR * PIXELSIZE); i += PIXELSIZE) {
		for (int j = 0; j < (PPC * PIXELSIZE); j += PIXELSIZE) {

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
