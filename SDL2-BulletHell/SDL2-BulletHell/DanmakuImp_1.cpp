#include "DanmakuImp_1.h"
#include "Ring.h"

//CONSTRUCTOR

DanmakuImp_1::DanmakuImp_1() {}

DanmakuImp_1::~DanmakuImp_1() {}

//DANMAKU_LOGIC

vector<Group*> DanmakuImp_1::create()
{
	//TODO Add Group* to the vector<Group*> here
	return vector<Group*>{ new Ring(360, 0, 1, 0, 0)};
}

void DanmakuImp_1::update()
{
	//TODO Update Group* inside the vector<Group*> here
}

void DanmakuImp_1::die()
{
	//TODO clear Group* from inside the vector<Group*> here
}
