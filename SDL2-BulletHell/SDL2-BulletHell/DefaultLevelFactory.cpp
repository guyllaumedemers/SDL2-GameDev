#include "DefaultLevelFactory.h"
#include "Danmaku_1.h"
#include "DanmakuImp_1.h"

//FACTORY_LOGIC

vector<Spawner*> DefaultLevelFactory::create()
{
	return {
		new Spawner(new Danmaku_1(new DanmakuImp_1()), new Timer(chrono::milliseconds{1000}))
	};
}
