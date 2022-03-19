#pragma once
#include "IDanmakuImp.h"

class IDanmaku
{
protected:

	//FIELDS

	IDanmakuImp* imp = nullptr;

	//CONSTRUCTOR

	IDanmaku() = default;

public:

	//CONSTRUCTOR

	IDanmaku(const IDanmaku&) = delete;

	IDanmaku(IDanmaku&&) = delete;

	virtual ~IDanmaku() {};

	//DANMAKU_LOGIC

	virtual void create(const Vector2d&) = 0;

	virtual void update(const double&) = 0;

	virtual void render(SDL_Renderer*) = 0;

	virtual void die() = 0;
};

