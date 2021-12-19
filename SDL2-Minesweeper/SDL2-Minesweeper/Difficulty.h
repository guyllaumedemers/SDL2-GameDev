#pragma once
#include "Mode.h"

struct Difficulty
{
private:

	Difficulty(int w, int h, int bombs, int flags);

public:

	int m_Width = 0;

	int m_Height = 0;

	int m_Bombs = 0;

	int m_Flags = 0;

	Difficulty(Mode mode);

	~Difficulty();
};

