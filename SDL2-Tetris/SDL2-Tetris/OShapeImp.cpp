#include "OShapeImp.h"
#include "TextureManager.h"

//CONSTRUCTOR

OShapeImp::OShapeImp()
{
	this->texture = TextureManager::getTexture("Yellow");
	this->tiles[0][0] = true;
	this->tiles[1][0] = true;
	this->tiles[1][1] = true;
	this->tiles[0][1] = true;
}

OShapeImp::~OShapeImp()
{
}

//IMP_LOGIC

void OShapeImp::flip()
{
}

void OShapeImp::move()
{
}
