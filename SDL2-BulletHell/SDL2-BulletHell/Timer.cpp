#include "Timer.h"

bool Timer::hasFinished()
{
	if (getDeltaTime() >= threshold) {
		last = std::chrono::high_resolution_clock::now();
		return true;
	}
	return false;
}

Timer::Timer(std::chrono::milliseconds threshold) : last(std::chrono::high_resolution_clock::now()), threshold(threshold)
{
}

Timer::~Timer()
{
}

std::chrono::milliseconds Timer::getDeltaTime()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - last);
}
