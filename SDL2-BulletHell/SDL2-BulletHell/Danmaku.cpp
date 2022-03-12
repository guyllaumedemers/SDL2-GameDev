#include "Danmaku.h"

//CONSTRUCTOR

Danmaku::Danmaku(IDanmakuImp* imp)
{
	this->imp = imp;
}

Danmaku::~Danmaku() {}

//DANMAKU_LOGIC

void Danmaku::create(const Vector2d& location)
{
	imp->create(location);
}

void Danmaku::update()
{
	imp->update();
}

void Danmaku::die()
{
	imp->die();
}