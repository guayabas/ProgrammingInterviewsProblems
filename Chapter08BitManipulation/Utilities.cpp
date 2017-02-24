#include "Utilities.h"
#include <cstdio>

void printArray(unsigned int ** buffer, unsigned int size)
{
	if (!buffer) return;
	for (unsigned int n = 0; n < size; ++n) printf("%d ", (*buffer)[n]);
	printf("\n");
}

void printArray(int ** buffer, unsigned int size)
{
	if (!buffer) return;
	for (unsigned int n = 0; n < size; ++n) printf("%d ", (*buffer)[n]);
	printf("\n");
}