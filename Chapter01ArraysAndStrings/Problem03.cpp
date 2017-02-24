#include "Problem03.h"
#include <iostream>
#include <stack>

/// Problem 03.
/// Reverse an input string word by word. A word is defined as a sequence if non-space characters
void Problem03::reverseString(std::string & inputString)
{
	std::stack<std::string> stackToReverseString;

	size_t numberLetterInWord = 0;
	size_t indexBlankSpace = 0;
	for (size_t i = 0; i < inputString.size(); ++i)
	{
		numberLetterInWord++;
		if (inputString[i] == ' ')
		{
			std::string word = inputString.substr(indexBlankSpace, numberLetterInWord - 1);
			numberLetterInWord = 0;
			indexBlankSpace = i + 1;

			stackToReverseString.push(word);
		}
	}
	stackToReverseString.push(inputString.substr(indexBlankSpace, numberLetterInWord));

	inputString = "";
	while (!stackToReverseString.empty())
	{
		inputString += stackToReverseString.top() + ((stackToReverseString.size() == 1) ? "" : " ");
		stackToReverseString.pop();
	}
}

void Problem03::unitTest()
{
	std::string inputString = "the sky is blue";
	std::cout << inputString << std::endl;
	reverseString(inputString);
	std::cout << inputString << std::endl;
	reverseString(inputString);
	std::cout << inputString << std::endl;
}