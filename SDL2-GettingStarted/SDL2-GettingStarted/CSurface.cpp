#include "CSurface.h"

CSurface::CSurface() : surface(nullptr)
{
}

CSurface::~CSurface()
{
	delete surface;
}

SDL_Surface* CSurface::OnLoad(SDL_Window* window, const char* File)
{
	SDL_Surface* temp = nullptr;

	if (File == NULL || File[0] == '\0') {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s String Args is Empty", "[GameSurface]");
		return nullptr;
	}
	else if ((temp = IMG_Load(File)) == NULL) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s File was not loaded - SDL : %s", "[GameSurface]", File);
		return nullptr;
	}
	else {
		return SDL_ConvertSurface(temp, SDL_GetWindowSurface(window)->format, NULL);
	}
}

bool CSurface::OnDraw(SDL_Surface* src, SDL_Surface* dest, uint16_t x, uint16_t y)
{
	if (src == nullptr || dest == nullptr) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s Surfaces were not loaded - SDL", "[GameSurface]");
		return false;
	}

	SDL_Rect destRect;
	destRect.x = x;
	destRect.y = y;

	return SDL_BlitSurface(src, NULL, dest, &destRect);
}

bool CSurface::OnDraw(SDL_Surface* src, SDL_Surface* dest, uint16_t x, uint16_t y, uint16_t x2, uint16_t y2, uint16_t w, uint16_t h)
{
	if (src == nullptr || dest == nullptr) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s Surfaces were not loaded - SDL", "[GameSurface]");
		return false;
	}

	SDL_Rect destRect;
	destRect.x = x;
	destRect.y = y;

	SDL_Rect srcRect;
	srcRect.x = x2;
	srcRect.y = y2;
	srcRect.w = w;
	srcRect.h = h;

	return SDL_BlitSurface(src, &srcRect, dest, &destRect);
}

void CSurface::Set(SDL_Surface* next)	// this would be better with move semantics, currently has two pointer pointing at the same adress in memory
{
	if (next == NULL) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s pointer is NULL", "[GameSurface]");
		return;
	}
	else {
		if (surface == nullptr) {
			surface = new SDL_Surface(*next);
		}
		else {
			SDL_FreeSurface(surface);
			surface = next;
		}
		return;
	}
}

SDL_Surface* CSurface::Get()
{
	return surface;
}
