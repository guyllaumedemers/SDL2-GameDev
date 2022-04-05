#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>

using namespace std;
class ImageLoader
{
public:

	//IMAGE_LOADER_LOGIC

	static SDL_Surface* loadCPURendering(SDL_Surface*, string path);

	static SDL_Texture* loadGPURendering(SDL_Renderer*, string path);
};

