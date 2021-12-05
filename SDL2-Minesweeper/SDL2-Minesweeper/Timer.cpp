#include "Timer.h"
#include <time.h>
#include <iomanip>

Timer::Timer(double maxTime)
{
	m_ResetTime = maxTime;
	m_StartTic = clock();
}

Timer::~Timer()
{
}

bool Timer::run()
{
	if (getTime() < m_ResetTime) {
		return true;
	}
	return false;
}

void Timer::RegisterToTimerCallback(EventHandler myEvent)
{
	eventHandler = myEvent;
}

void Timer::onTimerCallback()
{
	if (eventHandler != nullptr) {
		eventHandler();
	}
}

double Timer::getTime()
{
	return (clock() - m_StartTic) / CLOCKS_PER_SEC;
}
