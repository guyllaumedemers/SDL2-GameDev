#include "DefaultLevelFactory.h"
#include "Danmaku.h"
#include "DanmakuImp_1.h"

//FACTORY_LOGIC

vector<Spawner*> DefaultLevelFactory::create()
{
	return {
		new Spawner(
			new Danmaku(new DanmakuImp_1()),
			new Timer(chrono::milliseconds{1000}),
			Vector2d(0,0))
	};
}
