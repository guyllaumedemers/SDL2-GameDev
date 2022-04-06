#pragma once
#include "TetrominoeImp.h"

class InverseZShapeImp : public virtual TetrominoeImp
{
private:

	//CONSTRUCTOR

	InverseZShapeImp(const InverseZShapeImp&) = delete;

	InverseZShapeImp(InverseZShapeImp&&) = delete;

public:

	//CONSTRUCTOR

	InverseZShapeImp();

	~InverseZShapeImp();

	//IMP_LOGIC

	void flip() override;

	void move() override;
};

