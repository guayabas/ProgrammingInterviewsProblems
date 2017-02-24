#include "BinaryTree.h"
#include "Problem02.h"
#include "TreeNode.h"
#include <iostream>

/// Problem 02.
/// Given a binary tree, return the level order traversal of its nodes' values (i.e. from left to right
/// level by level)
template<typename T>
void Problem02::levelOrderTraversal(TreeNode<T> * treenode, int level, std::vector<std::queue<int>> & elementInLevel)
{
	if (treenode)
	{
		elementInLevel[level].push(treenode->value);
		levelOrderTraversal(treenode->left, level + 1, elementInLevel);
		levelOrderTraversal(treenode->right, level + 1, elementInLevel);
	}
}

void Problem02::unitTest()
{
	BinaryTree<int> binaryTreeToTraverse;
	binaryTreeToTraverse.insertElement(0x03, &(binaryTreeToTraverse.root));
	binaryTreeToTraverse.insertElement(0x09, &(binaryTreeToTraverse.root));
	binaryTreeToTraverse.insertElement(0x14, &(binaryTreeToTraverse.root));
	binaryTreeToTraverse.insertElement(0x0F, &(binaryTreeToTraverse.root->right));
	binaryTreeToTraverse.insertElement(0x07, &(binaryTreeToTraverse.root->right));

	std::vector<std::queue<int>> elementsInLevel;
	elementsInLevel.resize(10);
	levelOrderTraversal(binaryTreeToTraverse.root, 0, elementsInLevel);

	for (auto & queue : elementsInLevel)
	{
		if (queue.size() > 0)
		{
			std::cout << "[ ";
			while (!queue.empty())
			{
				std::cout << queue.front() << " "; queue.pop();
			}
			std::cout << "]";
		}
	}
	std::cout << std::endl;
}