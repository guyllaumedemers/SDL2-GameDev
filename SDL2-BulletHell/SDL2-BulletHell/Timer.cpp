#include "Timer.h"

Timer::Timer(double time)
{
	last = std::chrono::high_resolution_clock::now();
	threshold = time;
}

std::chrono::milliseconds Timer::getDeltaTime()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - last);
}
