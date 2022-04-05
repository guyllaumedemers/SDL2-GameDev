#include "Difficulty.h"

Difficulty::Difficulty(const int& w, const int& h)
{
	this->w = w;
	this->h = h;
}

Difficulty::Difficulty(const Mode& mode)
{
	switch (mode)
	{
	case Mode::beginner:
		*this = Difficulty
		{
			w = 10,
			h = 20
		};
		break;
	case Mode::medium:
		*this = Difficulty
		{
			w = 10,
			h = 24
		};
		break;
	case Mode::hard:
		*this = Difficulty
		{
			w = 20,
			h = 40
		};
		break;
	default:
		break;
	}
}

Difficulty::~Difficulty()
{
}
