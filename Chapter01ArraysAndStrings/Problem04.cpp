#include "Problem04.h"
#include "Utilities.h"
#include <iostream>

/// Problem 04.
/// Given two strings t and s, determine if they are isomorphic. Two strings are isomorphic if the characters in s
/// can be replaced to get t
bool Problem04::stringsIsomorphic(const std::string & string1, const std::string & string2, int ** lookUpTable)
{
	if (string1.size() != string2.size()) return false;

	size_t size = (string1.size() + string2.size()) / 2;
	for (size_t i = 0; i < size; ++i)
	{
		int characterString1 = int(string1[i]);
		int characterString2 = int(string2[i]);

		if ((*lookUpTable)[characterString1] == 0) (*lookUpTable)[characterString1] = characterString2;
		else if ((*lookUpTable)[characterString1] != characterString2) return false;
	}
	return true;
}

void Problem04::unitTest()
{
	const unsigned maxCharacters = 255;
	int * lookUpTable = new int[maxCharacters];

	std::string string1;
	std::string string2;

	for (unsigned int i = 0; i < maxCharacters; ++i) lookUpTable[i] = 0;
	string1 = "egg";
	string2 = "add";
	std::cout << "Strings: [" << string1 << ", " << string2 << "] ";
	if (stringsIsomorphic(string1, string2, &lookUpTable)) 
	{ 
		std::cout << "isomorphic\n"; 
		//printTable(&lookUpTable, maxCharacters); 
	}
	else std::cout << "not isomorphic\n";

	for (unsigned int i = 0; i < maxCharacters; ++i) lookUpTable[i] = 0;
	string1 = "foo";
	string2 = "bar";
	std::cout << "Strings: [" << string1 << ", " << string2 << "] ";
	if (stringsIsomorphic(string1, string2, &lookUpTable))
	{
		std::cout << "isomorphic\n"; 
		//printTable(&lookUpTable, maxCharacters);
	}
	else std::cout << "not isomorphic\n";

	delete[] lookUpTable;
}