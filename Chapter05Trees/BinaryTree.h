#pragma once

template<typename T>
class TreeNode;

template<typename T>
class BinaryTree
{
public:
	BinaryTree(); ~BinaryTree();
	void insertElement(const T &, TreeNode<T> **);
	void deleteTree();

	TreeNode<T> * root;
};