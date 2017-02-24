#include "Problem02.h"
#include "Utilities.h"
#include <iostream>
#include <cmath>
#include <stack>

/// Problem 02.
/// Reverse bits of a given 32 bits unsigned integer
void Problem02::reverseBits(unsigned int number)
{
	unsigned int numberBits = 31;
	unsigned int * binaryRepresentation = new unsigned int[numberBits + 1]{ 0 };

	transformDecimalToBinary(number, binaryRepresentation, numberBits);
	std::cout << transformBinaryToDecimal(binaryRepresentation, numberBits) << ": ";
	printArray(&binaryRepresentation, numberBits + 1);

	std::stack<int> reverseOrderBits;
	for (unsigned int i = 0; i <= numberBits; ++i) reverseOrderBits.push(binaryRepresentation[i]);
	for (unsigned int i = 0; i <= numberBits; ++i)
	{
		binaryRepresentation[i] = reverseOrderBits.top(); 
		reverseOrderBits.pop();
	}

	std::cout << transformBinaryToDecimal(binaryRepresentation, numberBits) << ": ";
	printArray(&binaryRepresentation, numberBits + 1);
}

void Problem02::transformDecimalToBinary(unsigned int number, unsigned int * buffer, unsigned int numberBits)
{
	unsigned int divisor = (1 << numberBits);

	while (divisor > 1)
	{
		unsigned int bitValue = (number / divisor);
		number %= divisor;
		divisor /= 2;
		buffer[numberBits--] = bitValue;
	}
	buffer[0] = (number / divisor);
}

unsigned int Problem02::transformBinaryToDecimal(unsigned int * buffer, unsigned int numberBits)
{
	unsigned int number = 0;
	for (unsigned int i = 0; i <= numberBits; ++i) if (buffer[i]) number += (1 << i);
	return number;
}

void Problem02::unitTest()
{
	unsigned int numberToReverse;

	numberToReverse = 26;
	reverseBits(numberToReverse);

	numberToReverse = 468;
	reverseBits(numberToReverse);

	numberToReverse = 43261596;
	reverseBits(numberToReverse);
}