#pragma once
#include <ctime>
#include <iostream>
#include <functional>

typedef std::function<void()> EventHandler;

class Timer
{
private:

	EventHandler m_EventHandler;

	std::clock_t m_StartTic;

	double m_ResetTime;

public:

	Timer(double maxTime);

	~Timer();

	bool run();

	void RegisterToTimerCallback(EventHandler myEvent);

	void onTimerCallback();

	double getTime();
};

