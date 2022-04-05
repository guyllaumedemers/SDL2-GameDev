#include "Tetrominoe.h"

//CONSTRUCTOR

Tetrominoe::Tetrominoe(TetrominoeImp* imp)
{
	this->imp = imp;
}

Tetrominoe::~Tetrominoe()
{
	delete imp;
	imp = nullptr;
}

//TETROMINOE_LOGIC

void Tetrominoe::flip() const
{
	imp->flip();
}

void Tetrominoe::move() const
{
	imp->move();
}
