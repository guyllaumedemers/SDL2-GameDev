#include "Spawner.h"

//CONSTRUCTOR

Spawner::Spawner(IDanmaku* danmaku, Timer* spawnRate, const Vector2d& location) : danmaku(danmaku), spawnRate(spawnRate), location(location) {}

Spawner::~Spawner() {}

//SPAWNER_LOGIC

void Spawner::create()
{
	danmaku->create(location);
}

void Spawner::update()
{
	//TODO Update Spawner Position if needed to make various pattern starting point
	danmaku->update();
}

void Spawner::die()
{
	danmaku->die();
}
