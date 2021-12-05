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
	m_EventHandler = myEvent;
}

void Timer::onTimerCallback()
{
	if (m_EventHandler != nullptr) {
		m_EventHandler();
	}
}

double Timer::getTime()
{
	return (clock() - m_StartTic) / CLOCKS_PER_SEC;
}
