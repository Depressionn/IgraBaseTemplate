#pragma once
class Time {
public:
	Time();
	~Time();
	static __int64 freq;
	static __int64 startCounts, lastTimeCounts;
	static float deltaTime;

public:
	static bool Start();
	static void UpdateDeltaTime();
};

