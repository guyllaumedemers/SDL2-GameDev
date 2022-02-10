#pragma once
#include <SDL.h>
#include <string>

class ImageLoader
{
public:

	static SDL_Texture* loadGPUTexture(const std::string path);
};

