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
		DBG_NEW Ring(location, 045, 0.100f, 0, 0, 90, TextureManager::getTexture("CP1")),
		DBG_NEW Ring(location, 045, 0.050f, 0, 0, 45, TextureManager::getTexture("DP1")),
		DBG_NEW Ring(location, 045, 0.035f, 0, 0, 120, TextureManager::getTexture("DP1")),
		DBG_NEW Ring(location, 045, 0.015f, 0, 0, 145, TextureManager::getTexture("CPG1"))
	};
}

void DanmakuImp_1::update()
{
	for (auto& it : subpatterns) {
		it->update();
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
