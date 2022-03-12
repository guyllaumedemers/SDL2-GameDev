#pragma once
#include <vector>
#include "Group.h"
#include "Vector2d.h"

using namespace std;
class IDanmakuImp
{
public:

	//DESTRUCTOR

	virtual ~IDanmakuImp() {};

	//DANMAKU_LOGIC

	virtual vector<Group*> create(const Vector2d&) = 0;
};

