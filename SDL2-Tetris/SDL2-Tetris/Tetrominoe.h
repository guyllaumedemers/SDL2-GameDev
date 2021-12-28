#pragma once
#include <SDL.h>
#include "Shape.h"

struct Tetrominoe
{
private:

	Shape* m_Shape = nullptr;

public:

	Tetrominoe(Shape* shape);

	~Tetrominoe();
};

