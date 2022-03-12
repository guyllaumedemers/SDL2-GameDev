#pragma once
#include "IDanmakuImp.h"

class DanmakuImp_1 : virtual public IDanmakuImp
{
public:

	//CONSTRUCTOR

	DanmakuImp_1();

	virtual ~DanmakuImp_1();

	//DANMAKU_LOGIC

	void create(const Vector2d&) override;

	void update() override;

	void render(SDL_Renderer*) override;

	void die() override;
};

