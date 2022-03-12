#pragma once
#include <vector>
#include "Group.h"
#include "Vector2d.h"

using namespace std;
class IDanmakuImp
{
protected:

	//FIELDS

	vector<Group*> subpatterns;

public:

	//DESTRUCTOR

	virtual ~IDanmakuImp() {};

	//DANMAKU_LOGIC

	virtual void create(const Vector2d&) = 0;

	virtual void update() = 0;

	virtual void die() = 0;
};

