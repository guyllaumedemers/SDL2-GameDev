#pragma once
#include "TetrominoeImp.h"

class LShapeImp : public virtual TetrominoeImp
{
private:

	//CONSTRUCTOR

	LShapeImp(const LShapeImp&) = delete;

	LShapeImp(LShapeImp&&) = delete;

public:

	//CONSTRUCTOR

	LShapeImp();

	~LShapeImp();

	//IMP_LOGIC

	void flip() override;

	void move() override;
};

