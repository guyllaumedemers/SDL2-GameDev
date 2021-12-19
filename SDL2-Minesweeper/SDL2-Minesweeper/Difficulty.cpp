#include "Difficulty.h"

Difficulty::Difficulty(int w, int h, int bombs, int flags)
{
	m_Width = w;
	m_Height = h;
	m_Bombs = bombs;
	m_Flags = flags;
}

Difficulty::Difficulty(Mode mode)
{
	switch (mode)
	{
	case Mode::beginner:
		*this = Difficulty
		{
			m_Width = 8,
			m_Height = 8,
			m_Bombs = 10,
			m_Flags = 10
		};
		break;
	case Mode::medium:
		*this = Difficulty
		{
			m_Width = 16,
			m_Height = 16,
			m_Bombs = 40,
			m_Flags = 40
		};
		break;
	case Mode::hard:
		*this = Difficulty
		{
			m_Width = 30,
			m_Height = 16,
			m_Bombs = 99,
			m_Flags = 99
		};
		break;
	default:
		break;
	}
}

Difficulty::~Difficulty()
{
}
