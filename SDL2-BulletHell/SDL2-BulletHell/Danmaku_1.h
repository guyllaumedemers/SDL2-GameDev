#pragma once
#include "IDanmaku.h"

class Danmaku_1 : virtual public IDanmaku
{
public:

	//CONSTRUCTOR

	Danmaku_1(IDanmakuImp*);

	virtual ~Danmaku_1();

	//DANMAKU_LOGIC

	virtual void create(const Vector2d&) override;

	virtual void update(const Vector2d&) override;

	virtual void die() override;
};

