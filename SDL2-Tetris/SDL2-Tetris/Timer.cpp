#include "Timer.h"

Timer::Timer(unsigned int  threshold)
{
	m_Threshold = threshold;
	m_CurrentTime = SDL_GetTicks();
}

Timer::~Timer()
{
}

bool Timer::getTimeElapse()
{
	return (SDL_GetTicks() - m_CurrentTime) >= m_Threshold;
}

void Timer::reset()
{
	m_CurrentTime = SDL_GetTicks();
}
