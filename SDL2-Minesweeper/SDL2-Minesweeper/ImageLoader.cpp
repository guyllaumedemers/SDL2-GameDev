#include "ImageLoader.h"

SDL_Surface* ImageLoader::loadCPURendering(SDL_Surface* windowSurface, std::string path)
{
	SDL_Surface* optimizeSurface = IMG_Load(path.c_str());

	if (optimizeSurface == nullptr) {
		SDL_Log("Cannot load BMP : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	optimizeSurface = SDL_ConvertSurface(optimizeSurface, (*windowSurface).format, 0);

	if (optimizeSurface == nullptr) {
		SDL_Log("Cannot Convert Surface : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	return optimizeSurface;
}

SDL_Texture* ImageLoader::loadGPURendering(SDL_Renderer* renderer, SDL_Surface* windowSurface, std::string path)
{
	SDL_Texture* optimizeTexture = IMG_LoadTexture(renderer, path.c_str());

	if (optimizeTexture == nullptr) {
		SDL_Log("Cannot load Texture : %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	return optimizeTexture;
}
