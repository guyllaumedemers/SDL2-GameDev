#include "Tetrominoe.h"

Tetrominoe::Tetrominoe(Shape* shape)
{
	m_Shape = shape;
}

Tetrominoe::~Tetrominoe()
{
	delete m_Shape;
	m_Shape = nullptr;
}
