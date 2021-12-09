#include "CellularAutomata.h"
#include "GameManager.h"
#include <iostream>

Point** CellularAutomata::s_NodeArr = nullptr;

bool** CellularAutomata::s_StateArr = nullptr;

int CellularAutomata::s_XOffset = 4;

int CellularAutomata::s_YOffset = 4;

int CellularAutomata::s_Population = 10;

/// <summary>
/// theres probably better way to initialize memory for the pointer targeting the 2d array
/// </summary>
void CellularAutomata::onInitialize(SDL_Renderer* ren)
{
	// initialize the 2d array with pointers
	s_NodeArr = new Point * [ROWS];
	s_StateArr = new bool* [ROWS];

	for (int k = 0; k < ROWS; ++k) {
		s_NodeArr[k] = new Point[COLUMNS];
		s_StateArr[k] = new bool[COLUMNS];
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
	// update the neighbors values
	onNeighborsUpdate();
	// do the cellular automata rendering logic here
	onRender(ren);
}

void CellularAutomata::onNeighborsUpdate()
{
	for (int i = s_YOffset; i < ROWS - s_YOffset; i += s_YOffset) {
		for (int j = s_XOffset; j < COLUMNS - s_XOffset; j += s_XOffset) {

			int count =
				s_NodeArr[i][j + s_XOffset].m_isAlive +
				s_NodeArr[i - s_YOffset][j + s_XOffset].m_isAlive +
				s_NodeArr[i + s_YOffset][j + s_XOffset].m_isAlive +
				s_NodeArr[i - s_YOffset][j].m_isAlive +
				s_NodeArr[i + s_YOffset][j].m_isAlive +
				s_NodeArr[i][j - s_XOffset].m_isAlive +
				s_NodeArr[i - s_YOffset][j - s_XOffset].m_isAlive +
				s_NodeArr[i + s_YOffset][j - s_XOffset].m_isAlive;

			if (s_NodeArr[i][j].m_isAlive) {
				s_StateArr[i][j] = (count == 2 || count == 3);
			}
			else {
				s_StateArr[i][j] = count == 3;
			}
		}
	}
}

void CellularAutomata::onRender(SDL_Renderer* ren)
{
	for (int i = 0; i < ROWS; i += s_YOffset) {
		for (int j = 0; j < COLUMNS; j += s_XOffset) {

			bool currentState = s_StateArr[i][j];
			s_NodeArr[i][j].m_isAlive = currentState;

			if (currentState) {
				SDL_RenderFillRect(ren, s_NodeArr[i][j].m_Rect);
			}
		}
	}
}

void CellularAutomata::onClear()
{
	for (int i = 0; i < ROWS; ++i) {
		delete s_NodeArr[i];
	}
	delete s_NodeArr;
	s_NodeArr = nullptr;
}
