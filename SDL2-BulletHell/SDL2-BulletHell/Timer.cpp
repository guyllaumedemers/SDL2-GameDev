#include "Timer.h"

//CONSTRUCTOR

Timer::Timer(milliseconds threshold) : last(high_resolution_clock::now()), threshold(threshold)
{
}

Timer::~Timer()
{
}

//TIMER_LOGIC

bool Timer::hasFinished()
{
	if (getDeltaTime() >= threshold) {
		last = high_resolution_clock::now();
		return true;
	}
	return false;
}

steady_clock::time_point Timer::setTimestamp()
{
	return high_resolution_clock::now();
}

void Timer::printExecutionTime(steady_clock::time_point& start)
{
	cout << "Execution Time: " <<
		duration_cast<microseconds>(high_resolution_clock::now() - start).count() << "us, " <<
		duration_cast<milliseconds>(high_resolution_clock::now() - start).count() << "ms" << endl;
}

milliseconds Timer::getDeltaTime()
{
	return duration_cast<milliseconds>(high_resolution_clock::now() - last);
}
