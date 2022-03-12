#include "DanmakuImp_1.h"
#include "Ring.h"
#include "TextureManager.h"

//CONSTRUCTOR

DanmakuImp_1::DanmakuImp_1() {}

DanmakuImp_1::~DanmakuImp_1() {}

//DANMAKU_LOGIC

vector<Group*> DanmakuImp_1::create(const Vector2d& location)
{
	return {
		new Ring(location, 12, 1, 0, 0, 0, TextureManager::getTexture("CP1"))
	};
}