#include "TShapeImp.h"
#include "TextureManager.h"

//CONSTRUCTOR

TShapeImp::TShapeImp()
{
	this->texture = TextureManager::getTexture("Purple");
	this->tiles[1][0] = true;
	this->tiles[1][1] = true;
	this->tiles[0][1] = true;
	this->tiles[1][2] = true;
}

TShapeImp::~TShapeImp()
{
}

//IMP_LOGIC

void TShapeImp::flip()
{
}

void TShapeImp::move()
{
}
