#include "LinkedList.h"
#include "Utilities.h"
#include "Problem01.h"
#include <cstdlib>
#include "Node.h"
#include <stack>
#include <ctime>

/// Problem 01.
/// You are given two linked lists representing two non-negative numbers. The digits are stored in reversed order and each
/// of their nodes contains a single digit. Add the two numbers and return it as a linked list
template<typename T>
void Problem01::addNumbers(LinkedList<T> * number1, LinkedList<T> * number2, LinkedList<T> * sum)
{
	std::stack<int> stacksum;
	std::stack<int> stack1;
	std::stack<int> stack2;

	Node<int> * head1 = number1->head();
	Node<int> * head2 = number2->head();

	while (head1->next)
	{
		stack1.push(head1->value);
		head1 = head1->next;
	}

	while (head2->next)
	{
		stack2.push(head2->value);
		head2 = head2->next;
	}

	int valuecarried = 0;
	while (!stack1.empty() || !stack2.empty())
	{
		int digit1 = stack1.top();
		stack1.pop();
		int digit2 = stack2.top();
		stack2.pop();

		int digitsum = (digit1 + digit2) + valuecarried;

		if (digitsum >= 10) { digitsum %= 10; valuecarried = 1; }
		else valuecarried = 0;

		stacksum.push(digitsum);
	}

	while (!stacksum.empty()) { sum->insert(stacksum.top()); stacksum.pop(); }
}

void Problem01::unitTest()
{
	srand((unsigned)time(0));

	LinkedList<int> number1;
	LinkedList<int> number2;
	LinkedList<int> sum;

	bool randomNumbers = true;
	if (randomNumbers)
	{
		for (unsigned int i = 0; i < 10; ++i)
		{
			number1.insert(RandomNumbers::generate(0, 10));
			number2.insert(RandomNumbers::generate(0, 10));
		}
	}
	else
	{
		number1.insert(2);
		number1.insert(4);
		number1.insert(3);
		number2.insert(5);
		number2.insert(6);
		number2.insert(4);
	}

	number1.print();
	number2.print();
	addNumbers(&number1, &number2, &sum);
	sum.print();
}