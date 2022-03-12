#include "Danmaku_1.h"

//CONSTRUCTOR

Danmaku_1::Danmaku_1(IDanmakuImp* imp)
{
	this->imp = imp;
}

Danmaku_1::~Danmaku_1() {}

//DANMAKU_LOGIC

void Danmaku_1::create(const Vector2d& location)
{
	subpatterns = imp->create(location);
}

void Danmaku_1::update()
{
	imp->update(subpatterns);
}

void Danmaku_1::die()
{
	imp->die();
}
