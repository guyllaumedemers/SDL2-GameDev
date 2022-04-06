#pragma once
#include "TetrominoeImp.h"

class ZShapeImp : public virtual TetrominoeImp
{
private:

	//CONSTRUCTOR

	ZShapeImp(const ZShapeImp&) = delete;

	ZShapeImp(ZShapeImp&&) = delete;

public:

	//CONSTRUCTOR

	ZShapeImp();

	~ZShapeImp();

	//IMP_LOGIC

	void flip() override;

	void move() override;
};

