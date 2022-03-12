#pragma once
#include "Spawner.h"
#include "Debugger.h"

class ISpawnerFactory
{
public:

	//FACTORY_LOGIC

	virtual Spawner* create() = 0;
};