#include "TetrominoeFactory.h"
#include "ResourceManager.h"
#include <iostream>

Tetrominoe* TetrominoeFactory::createTetrominoe(TetrominoeType type)
{
	SDL_Texture* texture = ResourceManager::getInstance()->getTexure(type);
	switch (type)
	{
	case TetrominoeType::O:
		return new Tetrominoe(type, texture);
	case TetrominoeType::I:
		return new Tetrominoe(type, texture);
	case TetrominoeType::S:
		return new Tetrominoe(type, texture);
	case TetrominoeType::Z:
		return new Tetrominoe(type, texture);
	case TetrominoeType::L:
		return new Tetrominoe(type, texture);
	case TetrominoeType::J:
		return new Tetrominoe(type, texture);
	case TetrominoeType::T:
		return new Tetrominoe(type, texture);
	default:
		std::cout << "ERROR::FACTORY_METHOD::DEFAULT_CASE" << std::endl;
		return nullptr;
	}
}
