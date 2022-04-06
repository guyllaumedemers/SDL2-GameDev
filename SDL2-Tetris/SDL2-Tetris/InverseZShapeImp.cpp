#include "InverseZShapeImp.h"
#include "TextureManager.h"

//CONSTRUCTOR

InverseZShapeImp::InverseZShapeImp()
{
	this->texture = TextureManager::getTexture("Green");
	this->tiles[1][0] = true;
	this->tiles[0][1] = true;
	this->tiles[1][1] = true;
	this->tiles[0][2] = true;
}

InverseZShapeImp::~InverseZShapeImp()
{
}

//IMP_LOGIC

void InverseZShapeImp::flip()
{
}

void InverseZShapeImp::move()
{
}
