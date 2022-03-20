#include "DanmakuImp_1.h"

//CONSTRUCTOR

DanmakuImp_1::DanmakuImp_1() {}

DanmakuImp_1::~DanmakuImp_1() {}

//DANMAKU_LOGIC

void DanmakuImp_1::create(const Vector2d& location)
{
	subpatterns = {
		DBG_NEW Ring(location, 120, 10.0f, 0.0f, 000.0f, 10.0f, TextureManager::getTexture("DP1")),
		DBG_NEW Stack(location, 10, 20.0f, 0.0f, 045.0f, 00.0f, 10.0f, TextureManager::getTexture("CPG1")),
		DBG_NEW Stack(location, 10, 20.0f, 0.0f, 135.0f, 00.0f, 10.0f, TextureManager::getTexture("CPG1")),
		DBG_NEW Stack(location, 10, 20.0f, 0.0f, 090.0f, 00.0f, 10.0f, TextureManager::getTexture("CPG1")),
		DBG_NEW Stack(location, 10, 20.0f, 0.0f, 225.0f, 00.0f, 10.0f, TextureManager::getTexture("CPG1")),
		DBG_NEW Stack(location, 10, 20.0f, 0.0f, 270.0f, 00.0f, 10.0f, TextureManager::getTexture("CPG1")),
		DBG_NEW Stack(location, 10, 20.0f, 0.0f, 315.0f, 00.0f, 10.0f, TextureManager::getTexture("CPG1"))
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
