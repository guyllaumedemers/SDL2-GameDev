#include "Spawner.h"

//CONSTRUCTOR

Spawner::Spawner(IDanmaku* danmaku, Timer* spawnRate) : danmaku(danmaku), spawnRate(spawnRate), isAlive(true) {}

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
