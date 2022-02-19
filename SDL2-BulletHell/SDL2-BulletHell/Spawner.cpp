#include "Spawner.h"

//CONSTRUCTOR

Spawner::Spawner(IDanmaku* danmaku) : danmaku(danmaku) {}

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
