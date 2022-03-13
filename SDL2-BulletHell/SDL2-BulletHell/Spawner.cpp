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
	danmaku->update();
}

void Spawner::render(SDL_Renderer* ren)
{
	danmaku->render(ren);
}

void Spawner::die()
{
	danmaku->die();
}
