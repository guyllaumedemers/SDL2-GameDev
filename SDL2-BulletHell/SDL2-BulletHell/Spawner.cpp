#include "Spawner.h"

//CONSTRUCTOR

Spawner::Spawner(IDanmaku* danmaku) : danmaku(danmaku), isAlive(true) {}

Spawner::~Spawner() {}

//SPAWNER_LOGIC

void Spawner::create()
{
	danmaku->create();
}

void Spawner::update()
{
	danmaku->update();
}

void Spawner::die()
{
	danmaku->die();
}
