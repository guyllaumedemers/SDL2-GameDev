#include "DifficultyController.h"

Difficulty* DifficultyController::m_CurrentDifficulty = nullptr;

DifficultyController::~DifficultyController()
{
	delete m_CurrentDifficulty;
	m_CurrentDifficulty = nullptr;
}

void DifficultyController::setDifficulty(const DifficultyEnum& selection)
{
	switch (selection) {
	case DifficultyEnum::beginner:
		m_CurrentDifficulty = new Difficulty{
			8,		// grid width
			8,		// grid height
			10,		// nb mines
			120		// timer value
		};
		break;
	case DifficultyEnum::intermediate:
		m_CurrentDifficulty = new Difficulty{
			13,		// grid width
			15,		// grid height
			40,		// nb mines
			240		// timer value
		};
		break;
	case DifficultyEnum::expert:
		m_CurrentDifficulty = new Difficulty{
			16,		// grid width
			30,		// grid height
			99,		// nb mines
			360		// timer value
		};
		break;
	};
}

Difficulty* DifficultyController::getDifficulty()
{
	return m_CurrentDifficulty;
}
