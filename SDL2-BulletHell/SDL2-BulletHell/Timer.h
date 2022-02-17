#pragma once
#include <chrono>

struct Timer
{
public:
	bool hasFinished();

	Timer(std::chrono::milliseconds threshold);

	~Timer();
private:
	std::chrono::milliseconds getDeltaTime();
	std::chrono::high_resolution_clock::time_point last;
	std::chrono::milliseconds threshold;
};

