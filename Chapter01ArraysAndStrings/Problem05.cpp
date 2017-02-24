#include "Problem05.h"
#include "Utilities.h"
#include <iostream>
#include <ctime>

/// Problem 05.
/// Determine whether an integer is a palindrome. Do this without extra space
bool Problem05::isNumberPalindrome(int number)
{
	if (number < 0) return false;

	int localNumber = number;

	int numberDigits = 0;
	do { numberDigits++; } while ((localNumber /= 10) != 0);

	int rightNumber = number;
	int leftNumber = number;

	int middle = (numberDigits / 2);
	for (int i = 0; i < middle; ++i)
	{
		int leftDivisor = 10;
		int leftDigit = (leftNumber % leftDivisor);
		leftNumber /= leftDivisor;

		int rightDivisor = (int)std::pow(10, (numberDigits - i - 1));
		int rightDigit = (rightNumber / rightDivisor);
		rightNumber %= rightDivisor;

		if (leftDigit != rightDigit) return false;
	}

	return true;
}

void Problem05::unitTest()
{
	srand((unsigned)time(0));

	int numberToCheckPalindrome;

	numberToCheckPalindrome = 121;
	std::cout << numberToCheckPalindrome << " is palindrome: " << boolToString(isNumberPalindrome(numberToCheckPalindrome)) << std::endl;

	numberToCheckPalindrome = 1221;
	std::cout << numberToCheckPalindrome << " is palindrome: " << boolToString(isNumberPalindrome(numberToCheckPalindrome)) << std::endl;

	numberToCheckPalindrome = 15744751;
	std::cout << numberToCheckPalindrome << " is palindrome: " << boolToString(isNumberPalindrome(numberToCheckPalindrome)) << std::endl;

	numberToCheckPalindrome = RandomNumbers::generate(0, 100000);
	std::cout << numberToCheckPalindrome << " is palindrome: " << boolToString(isNumberPalindrome(numberToCheckPalindrome)) << std::endl;
}