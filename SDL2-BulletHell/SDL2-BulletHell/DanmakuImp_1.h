#pragma once
#include "IDanmakuImp.h"

class DanmakuImp_1 : virtual public IDanmakuImp
{
public:

	//CONSTRUCTOR

	DanmakuImp_1();

	virtual ~DanmakuImp_1();

	//DANMAKU_LOGIC

	void create() override;

	void update() override;

	void die() override;
};
