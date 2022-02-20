#pragma once
#include "IDanmakuImp.h"

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

	virtual void create() = 0;

	virtual void update() = 0;

	virtual void die() = 0;
};
