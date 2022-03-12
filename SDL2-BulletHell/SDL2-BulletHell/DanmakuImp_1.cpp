#include "DanmakuImp_1.h"
#include "Ring.h"
#include "TextureManager.h"

//CONSTRUCTOR

DanmakuImp_1::DanmakuImp_1() {}

DanmakuImp_1::~DanmakuImp_1() {}

//DANMAKU_LOGIC

void DanmakuImp_1::create(const Vector2d& location)
{
	subpatterns = {
		DBG_NEW Ring(location, 120, 0.01f, 0, 0, 0, TextureManager::getTexture("CP1"))
	};
}

void DanmakuImp_1::update()
{
	//TODO Bridge Pattern Could be triggering external behaivour depending on the imp after a period of time
	for (auto& it : subpatterns) it->update();
}

void DanmakuImp_1::render(SDL_Renderer* ren)
{
	for (auto& it : subpatterns) it->render(ren);
}

void DanmakuImp_1::die()
{
	//TODO Bridge Pattern Could be triggering external behaivour depending on the imp on death
	for (auto& it : subpatterns) {
		delete it;
		it = nullptr;
	}
	subpatterns.clear();
}
