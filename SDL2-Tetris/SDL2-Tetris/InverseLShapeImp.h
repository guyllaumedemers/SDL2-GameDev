#pragma once
#include "TetrominoeImp.h"

class InverseLShapeImp : public virtual TetrominoeImp
{
private:

	//CONSTRUCTOR

	InverseLShapeImp(const InverseLShapeImp&) = delete;

	InverseLShapeImp(InverseLShapeImp&&) = delete;

public:

	//CONSTRUCTOR

	InverseLShapeImp();

	~InverseLShapeImp();

	//IMP_LOGIC

	void flip() override;

	void move() override;
};

