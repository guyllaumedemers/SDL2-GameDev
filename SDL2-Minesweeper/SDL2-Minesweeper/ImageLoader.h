#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>

class ImageLoader
{
public:
	static SDL_Surface* loadCPURendering(SDL_Surface* surfaceDisplay, std::string path);

	static SDL_Texture* loadGPURendering(SDL_Renderer* renderer, SDL_Surface* surfaceDisplay, std::string path);
};
