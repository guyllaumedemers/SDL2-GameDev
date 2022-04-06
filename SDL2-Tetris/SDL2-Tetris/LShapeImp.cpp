#include "LShapeImp.h"
#include "TextureManager.h"
#include "Debugger.h"

//CONSTRUCTOR

LShapeImp::LShapeImp()
{
	this->texture = TextureManager::getTexture("Orange");
	this->tiles[1][0] = true;
	this->tiles[1][1] = true;
	this->tiles[1][2] = true;
	this->tiles[0][2] = true;
}

LShapeImp::~LShapeImp()
{
}

//IMP_LOGIC

void LShapeImp::flip()
{
}

void LShapeImp::move()
{
}
