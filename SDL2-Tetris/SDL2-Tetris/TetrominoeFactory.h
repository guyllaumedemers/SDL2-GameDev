#pragma once
#include "TetrominoeType.h"
#include "Tetrominoe.h"

class TetrominoeFactory
{
public:

	static Tetrominoe* createTetrominoe(TetrominoeType type);
};

