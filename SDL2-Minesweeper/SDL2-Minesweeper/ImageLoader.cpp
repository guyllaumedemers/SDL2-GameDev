#include "ImageLoader.h"

SDL_Surface* ImageLoader::loadCPURendering(SDL_Surface* surfaceDisplay, std::string path)
{
	SDL_Surface* optimizeSurface = IMG_Load(path.c_str());

	if (optimizeSurface == nullptr) {
		SDL_Log("Cannot load BMP : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	optimizeSurface = SDL_ConvertSurface(optimizeSurface, surfaceDisplay->format, 0);

	if (optimizeSurface == nullptr) {
		SDL_Log("Cannot Convert Surface : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	return optimizeSurface;
}

SDL_Texture* ImageLoader::loadGPURendering(SDL_Renderer* renderer, SDL_Surface* surfaceDisplay, std::string path)
{
	SDL_Surface* optimizeSurface = loadCPURendering(surfaceDisplay, path);
	SDL_Texture* optimizeTexture = SDL_CreateTextureFromSurface(renderer, optimizeSurface);

	if (optimizeTexture == nullptr) {
		SDL_Log("Cannot load Texture : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_FreeSurface(optimizeSurface);

	return optimizeTexture;
}
