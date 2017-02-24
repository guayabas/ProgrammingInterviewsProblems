#pragma once

template<typename T>
bool binarySearch(T value, const T * buffer, int left, int right)
{
	if (left > right || left < 0 || right < 0) return false;

	int middlePoint = (left + right) / 2;
	if (buffer[middlePoint] == value) return true;

	if (buffer[middlePoint] > value) return binarySearch(value, buffer, left, middlePoint - 1);
	else return binarySearch(value, buffer, middlePoint + 1, right);
}