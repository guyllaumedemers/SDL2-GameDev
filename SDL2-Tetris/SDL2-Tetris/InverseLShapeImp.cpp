#include "InverseLShapeImp.h"
#include "TextureManager.cpp"

//CONSTRUCTOR

InverseLShapeImp::InverseLShapeImp()
{
	this->texture = TextureManager::getTexture("Blue");
	this->tiles[0][0] = true;
	this->tiles[1][0] = true;
	this->tiles[1][1] = true;
	this->tiles[1][2] = true;
}

InverseLShapeImp::~InverseLShapeImp()
{
}

//IMP_LOGIC

void InverseLShapeImp::flip()
{
}

void InverseLShapeImp::move()
{
}
