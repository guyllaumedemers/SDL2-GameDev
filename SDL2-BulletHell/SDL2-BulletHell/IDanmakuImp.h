#pragma once

class IDanmakuImp
{
public:

	//DESTRUCTOR

	virtual ~IDanmakuImp() {};

	//DANMAKU_LOGIC

	virtual void create() = 0;

	virtual void update() = 0;

	virtual void die() = 0;
};

