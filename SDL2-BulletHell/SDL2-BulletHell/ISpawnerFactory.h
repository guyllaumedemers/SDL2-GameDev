#pragma once
#include "Spawner.h"

class ISpawnerFactory
{
public:

	//FACTORY_LOGIC

	virtual Spawner* create() = 0;
};