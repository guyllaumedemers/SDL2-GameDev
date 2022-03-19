#include "DefaultLevelFactory.h"
#include "Danmaku.h"
#include "DanmakuImp_1.h"
#include "SDLTimerImp.h"

//FACTORY_LOGIC

vector<Spawner*> DefaultLevelFactory::create()
{
	return {
		DBG_NEW Spawner(
			DBG_NEW Danmaku(DBG_NEW DanmakuImp_1()),
			DBG_NEW Timer(DBG_NEW SDLTimerImp()),
			Vector2d(300,200))
	};
}
