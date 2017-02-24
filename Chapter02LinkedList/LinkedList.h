#pragma once

template<typename T>
class Node;

template<typename T>
class LinkedList
{
public:
	LinkedList(); ~LinkedList();

	void insert(T);
	void remove(T);

	Node<T> * head();
	void print();

private:
	Node<T> * m_head;
};
