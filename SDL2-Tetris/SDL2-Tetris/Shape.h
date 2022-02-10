#pragma once
#include "TetrominoeType.h"

class Shape
{
public:

	Shape(TetrominoeType type);

	~Shape();

private:

	Shape(const int& row, const int& col);

	bool** tiles = nullptr;
};

