#include "Node.h"

template<typename T>
Node<T>::Node()
	: next(nullptr)
	, value(T(0))
{

}

template<typename T>
Node<T>::~Node()
{

}

template class Node<int>;