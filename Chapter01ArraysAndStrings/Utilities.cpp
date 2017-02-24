#define _CRT_SECURE_NO_WARNINGS
#include "Utilities.h"
#include <cstdlib>
#include <cstdio>

void printArray(int ** buffer, unsigned int size)
{
	if (!buffer) return;
	for (unsigned int n = 0; n < size; ++n) printf("%d ", (*buffer)[n]);
	printf("\n");
}

void printTable(int ** buffer, unsigned int size)
{
	if (!buffer) return;
	for (unsigned int n = 0; n < size; ++n) printf("%d -> %d\n", n, (*buffer)[n]);
}

std::string boolToString(bool value)
{
	return (value) ? "true" : "false";
}