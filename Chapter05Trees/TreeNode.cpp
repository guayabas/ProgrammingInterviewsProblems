#include "TreeNode.h"

template<typename T>
TreeNode<T>::TreeNode()
	: right(nullptr)
	, left(nullptr)
	, value(0)
{

}

template<typename T>
TreeNode<T>::~TreeNode()
{

}

template class TreeNode<int>;