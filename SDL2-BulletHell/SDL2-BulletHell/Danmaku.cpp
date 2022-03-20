#include "Danmaku.h"

//CONSTRUCTOR

Danmaku::Danmaku(IDanmakuImp* imp)
{
	this->imp = imp;
}

Danmaku::~Danmaku() {}

//DANMAKU_LOGIC

void Danmaku::create(const Vector2d& displacement)
{
	imp->create(displacement);
}

void Danmaku::update(const double& ms)
{
	imp->update(ms);
}

void Danmaku::render(SDL_Renderer* ren)
{
	imp->render(ren);
}

void Danmaku::die()
{
	imp->die();
}
