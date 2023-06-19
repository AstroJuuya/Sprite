#include "FrameTimer.h"

using namespace std::chrono;

// initiates by marking the current time
FrameTimer::FrameTimer()
{
	last = steady_clock::now();
}

// gets the duration in ms since last mark
float FrameTimer::Mark()
{
	const auto old = last;
	last = steady_clock::now();
	const duration<float> frameTime = last - old;
	return frameTime.count();
}
