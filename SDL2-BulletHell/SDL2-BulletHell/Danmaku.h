#pragma once
#include "IDanmaku.h"

class Danmaku : virtual public IDanmaku
{
public:

	//CONSTRUCTOR

	Danmaku(IDanmakuImp*);

	virtual ~Danmaku();

	//DANMAKU_LOGIC

	virtual void create(const Vector2d&) override;

	virtual void update() override;

	virtual void die() override;
};

