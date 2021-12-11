#include "CellularAutomata.h"
#include "GameManager.h"
#include <iostream>

Point CellularAutomata::s_NodeArr[PPR][PPC];

bool CellularAutomata::s_StateArr[PPR][PPC] = { {false} };

int CellularAutomata::s_RandomnessFactor = 10;

void CellularAutomata::onInitialize(SDL_Renderer* ren)
{
	if (s_NodeArr == nullptr) {
		SDL_Log("Point Arrray is not initialized : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	Point* temp = &s_NodeArr[0][0];

	for (int i = 0; i < PPR; i += PIXELSIZE) {
		for (int j = 0; j < PPC; j += PIXELSIZE) {
			(*temp).m_Rect = new SDL_Rect{
				i,
				j,
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
	Point* temp = nullptr;

	for (int i = 0; i < PPR; i += PIXELSIZE) {
		for (int j = 0; j < PPC; j += PIXELSIZE) {

			int count = 0;

		}
	}

	temp = nullptr;
	delete temp;
}

void CellularAutomata::onRender(SDL_Renderer* ren)
{

}
