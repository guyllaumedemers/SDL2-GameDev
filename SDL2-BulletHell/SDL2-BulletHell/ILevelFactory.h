#pragma once
#include <vector>
#include "Spawner.h"

class ILevelFactory
{
public:

	//FACTORY_LOGIC

	virtual vector<Spawner*> create() = 0;
};