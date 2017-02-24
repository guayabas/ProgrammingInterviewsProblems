#pragma once
#include "ProblemInterface.h"
#include <vector>
#include <queue>

template<typename T>
class TreeNode;

class Problem02
	: public ProblemInterface
{
public:
	void unitTest();

protected:
	template<typename T>
	void levelOrderTraversal(TreeNode<T> *, int, std::vector<std::queue<int>> &);
};