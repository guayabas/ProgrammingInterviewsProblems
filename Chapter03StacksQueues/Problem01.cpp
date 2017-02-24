#include "Problem01.h"
#include "Utilities.h"
#include <ctime>

/// Problem 01.
/// Reverse an integer
std::queue<int> Problem01::reverseInteger(int & number)
{
	std::queue<int> digits;

	digits.push(number % 10);
	number = abs(number);
	number /= 10;

	while ((number / 10) != 0)
	{
		int rightMostDigit = (number % 10);
		digits.push(rightMostDigit);
		number /= 10;
	}
	digits.push((number % 10));

	return digits;
}

void Problem01::unitTest()
{
	srand((unsigned)time(NULL));

	std::queue<int> reversedNumber;
	int numberToReverse;

	numberToReverse = 123;
	std::cout << "Number to reverse: " << numberToReverse << "\n";
	reversedNumber = reverseInteger(numberToReverse);
	printQueue(reversedNumber);
	
	numberToReverse = -123;
	std::cout << "Number to reverse: " << numberToReverse << "\n";
	reversedNumber = reverseInteger(numberToReverse);
	printQueue(reversedNumber);

	numberToReverse = RandomNumbers::generate(-100000, 100000);
	std::cout << "Number to reverse: " << numberToReverse << "\n";
	reversedNumber = reverseInteger(numberToReverse);
	printQueue(reversedNumber);
}