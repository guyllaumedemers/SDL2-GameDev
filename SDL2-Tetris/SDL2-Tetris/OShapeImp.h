#pragma once
#include "TetrominoeImp.h"

class OShapeImp : public virtual TetrominoeImp
{
private:

	//CONSTRUCTOR

	OShapeImp(const OShapeImp&) = delete;

	OShapeImp(OShapeImp&&) = delete;

public:

	//CONSTRUCTOR

	OShapeImp();

	~OShapeImp();

	//IMP_LOGIC

	void flip() override;

	void move() override;
};

