#include "Tetrominoe.h"

//CONSTRUCTOR

Tetrominoe::Tetrominoe(int* map)
{
	this->map = map;
}

Tetrominoe::~Tetrominoe()
{
	texture = nullptr;
	delete[] map;
	map = nullptr;
}

//TETROMINOE_LOGIC

void Tetrominoe::flip()
{
	//TODO Do logic for shifting array indexes
}

void Tetrominoe::move()
{
	//TODO Do logic for shifting array indexes
}
