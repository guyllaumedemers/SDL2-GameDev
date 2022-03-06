#include "ImageLoader.h"

//IMAGE_LOADER_LOGIC

SDL_Surface* ImageLoader::loadCPURendering(SDL_Surface* windowSurface, string path)
{
	SDL_Surface* optimizeSurface;
	if ((optimizeSurface = IMG_Load(path.c_str())) == nullptr) {
		SDL_Log("Cannot load BMP : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	if ((optimizeSurface = SDL_ConvertSurface(optimizeSurface, (*windowSurface).format, 0)) == nullptr) {
		SDL_Log("Cannot Convert Surface : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	return optimizeSurface;
}

SDL_Texture* ImageLoader::loadGPURendering(SDL_Renderer* renderer, string path)
{
	SDL_Texture* optimizeTexture;
	if ((optimizeTexture = IMG_LoadTexture(renderer, path.c_str())) == nullptr) {
		SDL_Log("Cannot load Texture : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	return optimizeTexture;
}
