#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>

class ImageLoader
{
public:

	static SDL_Surface* loadCPURendering(SDL_Surface* windowSurface, std::string path);

	static SDL_Texture* loadGPURendering(SDL_Renderer* renderer, std::string path);
};

