#include "pch.h"
Time::Time() {
}

Time::~Time() {
}

bool Time::Start() {
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li)) {
		return false;
	}
	Time::freq = li.QuadPart / 10;
	QueryPerformanceCounter(&li);

	startCounts = li.QuadPart;
	lastTimeCounts = li.QuadPart;
	return true;
}

void Time::UpdateDeltaTime() {
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	__int64 currentTimeCounts = li.QuadPart;
	deltaTime = (float)(currentTimeCounts - lastTimeCounts) / freq;
	lastTimeCounts = currentTimeCounts;
}

__int64 Time::freq;
__int64 Time::lastTimeCounts;
__int64 Time::startCounts;
float Time::deltaTime = 0;
