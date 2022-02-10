#pragma once
#include <SDL.h>
#include <unordered_map>
#include "TetrominoeType.h"

class ResourceManager
{
public:

	~ResourceManager();

	static ResourceManager* getInstance();

	void operator=(const ResourceManager&) = delete;

	SDL_Texture* getTexure(TetrominoeType type);

private:

	ResourceManager();

	static ResourceManager* instance;

	std::unordered_map<TetrominoeType, SDL_Texture*> textureMap;
};

