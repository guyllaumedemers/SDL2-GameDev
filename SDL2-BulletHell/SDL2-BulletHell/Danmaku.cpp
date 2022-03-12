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
	subpatterns = imp->create(location);
}

void Danmaku::update()
{
	for (auto& it : subpatterns) it->update();
}

void Danmaku::die()
{
	for (auto& it : subpatterns) {
		delete it;
		it = nullptr;
	}
	subpatterns.clear();
}
