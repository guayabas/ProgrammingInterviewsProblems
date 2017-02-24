#include "BinaryTree.h"
#include "Problem01.h"
#include "TreeNode.h"
#include <iostream>

/// Problem 01.
/// Implement a pre-order, post-order, and in-order binary tree traversal
template<typename T>
void Problem01::preOrderTraversal(TreeNode<T> * treenode)
{
	/// Pre-order process parent node before children
	if (treenode)
	{
		std::cout << treenode->value << " ";
		preOrderTraversal(treenode->left);
		preOrderTraversal(treenode->right);
	}
}

template<typename T>
void Problem01::inOrderTraversal(TreeNode<T> * treenode)
{
	/// In-order process parent left - parent - right
	if (treenode)
	{
		inOrderTraversal(treenode->left);
		std::cout << treenode->value << " ";
		inOrderTraversal(treenode->right);
	}
}

template<typename T>
void Problem01::postOrderTraversal(TreeNode<T> * treenode)
{
	/// Pre-order process children before parent
	if (treenode)
	{
		postOrderTraversal(treenode->left);
		postOrderTraversal(treenode->right);
		std::cout << treenode->value << " ";
	}
}


void Problem01::unitTest()
{
	BinaryTree<int> binaryTreeToTraverse;
	binaryTreeToTraverse.insertElement(1, &(binaryTreeToTraverse.root));
	binaryTreeToTraverse.insertElement(2, &(binaryTreeToTraverse.root));
	binaryTreeToTraverse.insertElement(3, &(binaryTreeToTraverse.root));
	binaryTreeToTraverse.insertElement(4, &(binaryTreeToTraverse.root->left));
	binaryTreeToTraverse.insertElement(5, &(binaryTreeToTraverse.root->left));
	binaryTreeToTraverse.insertElement(6, &(binaryTreeToTraverse.root->left->right));

	postOrderTraversal(binaryTreeToTraverse.root);
	std::cout << std::endl;

	inOrderTraversal(binaryTreeToTraverse.root);
	std::cout << std::endl;

	preOrderTraversal(binaryTreeToTraverse.root);
	std::cout << std::endl;
}