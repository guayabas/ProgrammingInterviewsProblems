#include "LinkedList.h"
#include "Problem02.h"
#include "Utilities.h"
#include <iostream>
#include "Node.h"

/// Problem 02.
/// Given a linked list, determine if it has a cycle in it
template<typename T>
bool Problem02::linkedListHasCycle(LinkedList<T> * linkedList)
{
	Node<T> * slowPointer = linkedList->head();
	Node<T> * fastPointer = linkedList->head();

	while (fastPointer && fastPointer->next)
	{
		fastPointer = fastPointer->next->next;
		slowPointer = slowPointer->next;

		if (fastPointer == slowPointer) return true;
	}

	return false;
}

void Problem02::unitTest()
{
	LinkedList<int> listWithNoCycle;
	listWithNoCycle.insert(1);
	listWithNoCycle.insert(2);
	std::cout << "Linked list has cycle : ";
	std::cout << boolToString(linkedListHasCycle(&listWithNoCycle));
	std::cout << "\n";
	listWithNoCycle.print();

	LinkedList<int> listWithCycle;
	listWithCycle.insert(1);
	listWithCycle.head()->next->next = listWithCycle.head();
	std::cout << "Linked list has cycle : ";
	std::cout << boolToString(linkedListHasCycle(&listWithCycle));
	std::cout << "\n";
	listWithCycle.print();
}