#pragma once
#include "Tetrominoe.h"
#include "TetrominoeImp.h"

class TetrominoeFactory
{
public:

	//FACTORY_LOGIC

	static Tetrominoe* factoryMethod(TetrominoeImp*);
};

