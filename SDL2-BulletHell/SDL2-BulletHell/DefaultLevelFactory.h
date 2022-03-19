#pragma once
#include "ILevelFactory.h"

class DefaultLevelFactory : virtual public ILevelFactory
{
public:

	//DESTRUCTOR

	~DefaultLevelFactory() {};

	//FACTORY_LOGIC

	vector<Spawner*> create() override;
};

