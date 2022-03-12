#pragma once
#include "IDanmakuImp.h"
#include "Vector2d.h"

using namespace std;
class IDanmaku
{
protected:

	//FIELDS

	IDanmakuImp* imp = nullptr;

public:

	//DESTRUCTOR

	virtual ~IDanmaku() {};

	//DANMAKU_LOGIC

	virtual void create(const Vector2d&) = 0;

	virtual void update() = 0;

	virtual void render(SDL_Renderer*) = 0;

	virtual void die() = 0;
};

