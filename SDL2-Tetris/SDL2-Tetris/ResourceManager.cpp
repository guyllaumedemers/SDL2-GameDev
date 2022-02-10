#include "ResourceManager.h"
#include <iostream>
#include "ImageLoader.h"

ResourceManager::ResourceManager() {
	SDL_Texture* textures = ImageLoader::loadGPUTexture("");

	// retrieve all textures from file
}

ResourceManager::~ResourceManager()
{
	for (auto& it : textureMap) {
		SDL_DestroyTexture(it.second);
		it.second = nullptr;
	}
	textureMap.clear();
}

ResourceManager* ResourceManager::getInstance()
{
	if (instance == nullptr) return instance = new ResourceManager();
	else return instance;
}

SDL_Texture* ResourceManager::getTexure(TetrominoeType type)
{
	if (textureMap.find(type) != textureMap.end()) {
		return textureMap.at(type);
	}
	std::cout << "ERROR::RESOURCES::MAP_DOESNT_CONTAINS_KEY" << std::endl;
	return nullptr;
}
