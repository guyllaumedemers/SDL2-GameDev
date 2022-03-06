#include "Level.h"

//CONSTRUCTOR

Level::Level(ILevelFactory* levelFactory)
{
	this->levelFactory = levelFactory;
}

Level::~Level()
{
	delete levelFactory;
	levelFactory = nullptr;
}

//LEVEL_LOGIC

vector<Spawner*> Level::create()
{
	return levelFactory->create();
}
