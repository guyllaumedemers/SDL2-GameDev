#pragma once
#include "Mode.h"

struct Difficulty
{
private:

	//FIELDS

	int w = 0;

	int h = 0;

	//CONSTRUCTOR

	Difficulty(const int&, const int&);

	Difficulty(const Difficulty&) = delete;

public:

	//CONSTRUCTOR

	Difficulty(const Mode&);

	~Difficulty();

	//GETTER

	int getWidth() { return w; }

	int getHeight() { return h; }
};

