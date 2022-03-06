#pragma once
#include <vector>
#include "Spawner.h"

class ILevelFactory
{
public:

	//DESTRUCTOR

	virtual ~ILevelFactory() {};

	//FACTORY_LOGIC

	virtual vector<Spawner*> create() = 0;
};