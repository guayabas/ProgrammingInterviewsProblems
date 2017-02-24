#pragma once
#include <string>

namespace RandomNumbers
{
	template<typename T>
	T generate(T a, T b)
	{
		return T(((b - a) * (std::rand() / (RAND_MAX - 1.0))) + a);
	}
}

void printArray(int **, unsigned int);
void printTable(int **, unsigned int);
std::string boolToString(bool);