#include "DanmakuImp_1.h"
#include "Ring.h"
#include "TextureManager.h"
#include "ThreadManager.h"

//CONSTRUCTOR

DanmakuImp_1::DanmakuImp_1() {}

DanmakuImp_1::~DanmakuImp_1() {}

//DANMAKU_LOGIC

void DanmakuImp_1::create(const Vector2d& location)
{
	subpatterns = {
		DBG_NEW Ring(location, 120, 10.0f, 0, 0, 10.0f, TextureManager::getTexture("DP1"))
	};
}

void DanmakuImp_1::update(const double& ms)
{
	for (auto& it : subpatterns) {
		it->update(ms);
	}
}

void DanmakuImp_1::render(SDL_Renderer* ren)
{
	for (auto& it : subpatterns) {
		it->render(ren);
	}
}

void DanmakuImp_1::die()
{
	for (auto& it : subpatterns) {
		delete it;
		it = nullptr;
	}
	subpatterns.clear();
}
