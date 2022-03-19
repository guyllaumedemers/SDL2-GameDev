#include "SDLTimerImp.h"

//CONSTRUCTOR

SDLTimerImp::SDLTimerImp() : previous(SDL_GetTicks64()) {}

SDLTimerImp::~SDLTimerImp() {}

//TIMER_LOGIC

void SDLTimerImp::ticks()
{
	delta = ((SDL_GetTicks64() - previous) * (fps / 1000.0f));
	if (delta > threshold) delta = threshold;
	previous = SDL_GetTicks64();
}

double SDLTimerImp::deltaTime()
{
	return delta;
}
