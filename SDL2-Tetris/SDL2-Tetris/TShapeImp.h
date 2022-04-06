#pragma once
#include "TetrominoeImp.h"

class TShapeImp : public virtual TetrominoeImp
{
private:

	//CONSTRUCTOR

	TShapeImp(const TShapeImp&) = delete;

	TShapeImp(TShapeImp&&) = delete;

public:

	//CONSTRUCTOR

	TShapeImp();

	~TShapeImp();

	//IMP_LOGIC

	void flip() override;

	void move() override;
};

