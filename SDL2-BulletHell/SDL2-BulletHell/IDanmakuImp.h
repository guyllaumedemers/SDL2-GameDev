#pragma once
#include <vector>
#include "Group.h"

using namespace std;
class IDanmakuImp
{
public:

	//DESTRUCTOR

	virtual ~IDanmakuImp() {};

	//DANMAKU_LOGIC

	virtual vector<Group*> create() = 0;

	virtual void update() = 0;

	virtual void die() = 0;
};

