#pragma once
#include <chrono>

struct Timer
{
private:

	//TIMER_LOGIC

	std::chrono::milliseconds getDeltaTime();

	//FIELDS

	std::chrono::high_resolution_clock::time_point last;
	std::chrono::milliseconds threshold;

public:

	//TIMER_LOGIC

	bool hasFinished();

	//CONSTRUCTOR

	Timer(std::chrono::milliseconds threshold);

	~Timer();
};

