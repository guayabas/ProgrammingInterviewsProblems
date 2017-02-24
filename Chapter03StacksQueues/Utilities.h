#pragma once
#include <iostream>
#include <queue>

namespace RandomNumbers
{
	template<typename T>
	T generate(T a, T b)
	{
		return T(((b - a) * (std::rand() / (RAND_MAX - 1.0))) + a);
	}
}

template<typename T>
void printQueue(std::queue<T> & queueContainer)
{
	while (!queueContainer.empty())
	{
		std::cout << queueContainer.front();
		queueContainer.pop();
	}
	std::cout << std::endl;
}