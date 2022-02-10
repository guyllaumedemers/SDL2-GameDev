#pragma once
#include <chrono>

struct Timer
{
public:
	std::chrono::milliseconds getDeltaTime();

	Timer(double time);

	Timer(const Timer&) = default;

	Timer(Timer&&) = default;
private:
	std::chrono::high_resolution_clock::time_point last;
	double threshold = 0.0f;
};

