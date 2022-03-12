#include "DefaultLevelFactory.h"
#include "Danmaku.h"
#include "DanmakuImp_1.h"

//FACTORY_LOGIC

vector<Spawner*> DefaultLevelFactory::create()
{
	return {
		DBG_NEW Spawner(
			DBG_NEW Danmaku(DBG_NEW DanmakuImp_1()),
			DBG_NEW Timer(chrono::milliseconds{1000}),
			Vector2d(200,200))
	};
}
