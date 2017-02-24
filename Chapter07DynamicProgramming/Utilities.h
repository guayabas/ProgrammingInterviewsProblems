#pragma once
#include <iostream>

template<typename T>
void printArray(T ** buffer, unsigned int left, unsigned int right)
{
	for (unsigned int i = left; i < right; ++i) std::cout << (*buffer)[i] << " ";
	std::cout << std::endl;
}