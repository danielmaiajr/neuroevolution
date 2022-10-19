#pragma once
#include <random>

static std::mt19937 default_generator(std::random_device{}());

class Random
{
	Random() {}

	float IFloat() { return std::uniform_real_distribution<float> {-1.0, 1.0}(default_generator); }
public:
	static Random& getInstance() 
	{
		static Random instance;
		return instance;
	}

	static float Float() { return getInstance().IFloat(); }
};