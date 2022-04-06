#include "ZShapeImp.h"
#include "TextureManager.cpp"

//CONSTRUCTOR

ZShapeImp::ZShapeImp()
{
	this->texture = TextureManager::getTexture("Red");
	this->tiles[0][0] = true;
	this->tiles[0][1] = true;
	this->tiles[1][1] = true;
	this->tiles[1][2] = true;
}

ZShapeImp::~ZShapeImp()
{
}

//IMP_LOGIC

void ZShapeImp::flip()
{
}

void ZShapeImp::move()
{
}
