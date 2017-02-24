#include "Problem01.h"
#include <iostream>

/// Problem 01.
/// Implement an algorithm to determine if a string has all unique characters.
/// What if you cannot use additional data structures?
bool Problem01::stringHasUniqueCharacters(const std::string & stringToCheck)
{
	const unsigned maxCharacters = 255;
	unsigned lookUpTable[maxCharacters] = { 0 };

	for (const auto & character : stringToCheck)
	{
		unsigned castCharacterToUnsigned = unsigned(character);
		if (lookUpTable[castCharacterToUnsigned]) return false;
		lookUpTable[castCharacterToUnsigned] = 1;
	}
	return true;
}

std::string Problem01::isUniqueConsolePrinting(bool value)
{
	return (value) ? " unique" : " not unique";
}

void Problem01::unitTest()
{
	std::string string1 = "Hello World";
	std::cout << "Testing : " << string1 << isUniqueConsolePrinting(stringHasUniqueCharacters(string1)) << "\n";
	std::string string2 = "Alejandro";
	std::cout << "Testing : " << string2 << isUniqueConsolePrinting(stringHasUniqueCharacters(string2)) << "\n";
}