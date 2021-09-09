#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

/* Blitting is the process of drawing image on screen*/

class CSurface					// SDL Coordinate System is Inverted on the Y-Axis meaning the Top-Right corner is 0,0
{
private:
	SDL_Surface* surface;		// SDL_Surface use sofware rendering -> CPU
public:
	// Constructor
	CSurface();
	// Destructor
	~CSurface();
	// Static Functions
	static SDL_Surface* OnLoad(SDL_Window* window, const char* File);
	static bool OnDraw(SDL_Surface* src, SDL_Surface* dest, uint16_t x, uint16_t y);
	static bool OnDraw(SDL_Surface* src, SDL_Surface* dest, uint16_t x, uint16_t y, uint16_t x2, uint16_t y2, uint16_t w, uint16_t h);
	void Set(SDL_Surface* next);
	SDL_Surface* Get();
};

