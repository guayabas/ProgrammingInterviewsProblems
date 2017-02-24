#include "Problem01.h"
#include "Problem02.h"
#include "Problem03.h"
#include <iostream>

static constexpr short numberOfTests = 3;

void selectTest(short testNumber)
{
	switch (testNumber)
	{
	default: std::cout << "Hello World!\n"; break;
	case 0x1: Problem01().unitTest(); break;
	case 0x2: Problem02().unitTest(); break;
	case 0x3: Problem03().unitTest(); break;
	}
}

int main(int argc, char ** argv)
{
	if (argc == 2) selectTest(atoi(argv[1]));
	else for (short i = 0; i <= numberOfTests; ++i) selectTest(i);
	std::cout << "Press any key ";
	std::cin.get(); return 0;
}