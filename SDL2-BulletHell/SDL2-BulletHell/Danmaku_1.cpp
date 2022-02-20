#include "Danmaku_1.h"

//CONSTRUCTOR

Danmaku_1::Danmaku_1(IDanmakuImp* imp)
{
	this->imp = imp;
}

Danmaku_1::~Danmaku_1() {}

//DANMAKU_LOGIC

void Danmaku_1::create()
{
	imp->create();
}

void Danmaku_1::update()
{
	imp->update();
}

void Danmaku_1::die()
{
	imp->die();
}
