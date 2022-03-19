#pragma once
#include "Group.h"

using namespace std;
class IDanmakuImp
{
protected:

	//FIELDS

	vector<Group*> subpatterns;

	//CONSTRUCTOR

	IDanmakuImp() = default;

public:

	//CONSTRUCTOR

	IDanmakuImp(const IDanmakuImp&) = delete;

	IDanmakuImp(IDanmakuImp&&) = delete;

	virtual ~IDanmakuImp() {};

	//DANMAKU_LOGIC

	virtual void create(const Vector2d&) = 0;

	virtual void update(const double&) = 0;

	virtual void render(SDL_Renderer*) = 0;

	virtual void die() = 0;
};

