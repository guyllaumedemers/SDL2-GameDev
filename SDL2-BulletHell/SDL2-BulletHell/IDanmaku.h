#pragma once
#include <vector>
#include "IDanmakuImp.h"
#include "Group.h"
#include "Vector2d.h"

using namespace std;
class IDanmaku
{
protected:

	//FIELDS

	IDanmakuImp* imp = nullptr;

	vector<Group*> subpatterns;

public:

	//DESTRUCTOR

	virtual ~IDanmaku() {};

	//DANMAKU_LOGIC

	virtual void create(const Vector2d&) = 0;

	virtual void update(const Vector2d&) = 0;

	virtual void die() = 0;
};

