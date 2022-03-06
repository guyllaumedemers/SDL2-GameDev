#include "DanmakuImp_1.h"
#include "Ring.h"
#include "TextureManager.h"

//CONSTRUCTOR

DanmakuImp_1::DanmakuImp_1() {}

DanmakuImp_1::~DanmakuImp_1() {}

//DANMAKU_LOGIC

vector<Group*> DanmakuImp_1::create()
{
	//TODO Pass the location of the spawner as argument to the create function
	return {
		new Ring(Vector2d(0,0), 12, 1, 0, 0, 0, TextureManager::getTexture("CP1"))
	};
}

void DanmakuImp_1::update()
{
	//TODO Update Group* inside the vector<Group*> here
}

void DanmakuImp_1::die()
{
	//TODO clear Group* from inside the vector<Group*> here
}
