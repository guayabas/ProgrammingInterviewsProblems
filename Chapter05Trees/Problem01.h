#pragma once
#include "ProblemInterface.h"

template<typename T>
class TreeNode;

class Problem01
	: public ProblemInterface
{
public:
	void unitTest();

protected:
	template<typename T>
	void postOrderTraversal(TreeNode<T> *);

	template<typename T>
	void preOrderTraversal(TreeNode<T> *);

	template<typename T>
	void inOrderTraversal(TreeNode<T> *);
};