#pragma once

struct  Difficulty
{
	unsigned short int m_GridWidth;
	unsigned short int m_GridHeight;
	unsigned short int m_NbMines;
	double m_Time;
};

enum class DifficultyEnum {
	beginner,
	intermediate,
	expert
};

class DifficultyController
{
private:
	static Difficulty* m_CurrentDifficulty;
public:
	~DifficultyController();

	static void setDifficulty(const DifficultyEnum& selection);

	static Difficulty* getDifficulty();
};

