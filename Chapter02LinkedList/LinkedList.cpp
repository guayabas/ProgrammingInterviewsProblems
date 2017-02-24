#include "LinkedList.h"
#include <iostream>
#include "Node.h"

template<typename T>
LinkedList<T>::LinkedList()
	: m_head(new Node<T>)
{

}

template<typename T>
LinkedList<T>::~LinkedList()
{
	Node<T> * p = m_head;
	Node<T> * q = m_head;

	while (q->next)
	{
		if (q->next->next == p->next) break;

		p = q;
		q = p->next;
		if (q) delete p;
	}
}

template<typename T>
void LinkedList<T>::insert(T value)
{
	Node<T> * p = m_head;
	Node<T> * q = m_head;

	while (q)
	{
		p = q;
		q = p->next;
	}
	p->next = new Node<T>;
	p->value = value;
}

template<typename T>
Node<T> * LinkedList<T>::head()
{
	return m_head;
}

template<typename T>
void LinkedList<T>::remove(T value)
{
	if (!m_head->next) return;

	Node<T> * p = m_head;
	Node<T> * q = m_head;
	while (q)
	{
		if (q->value == value)
		{
			p->next = q->next;
			delete q;
			return;
		}

		p = q;
		q = p->next;
	}
}

template<typename T>
void LinkedList<T>::print()
{
	Node<T> * p = m_head;
	Node<T> * q = m_head;

	while (q->next)
	{
		if (q->next->next == p->next) break;

		p = q;
		std::cout << p->value << " -> ";
		q = p->next;
	}
	std::cout << "\n";
}

template class LinkedList<int>;
