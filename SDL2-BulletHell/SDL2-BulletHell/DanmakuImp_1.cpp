#include "DanmakuImp_1.h"

//CONSTRUCTOR

DanmakuImp_1::DanmakuImp_1() {}

DanmakuImp_1::~DanmakuImp_1() {}

//DANMAKU_LOGIC

void DanmakuImp_1::create(const Vector2d& displacement)
{
	subpatterns = {
		DBG_NEW Stack(displacement, 1, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, TextureManager::getTexture("CPG1"))
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
