#include "BinaryTree.h"
#include "TreeNode.h"

template<typename T>
BinaryTree<T>::BinaryTree()
	: root(nullptr)
{

}

template<typename T>
BinaryTree<T>::~BinaryTree()
{
	deleteTree();
}

template<typename T>
void BinaryTree<T>::deleteTree()
{
	if (root) delete root; root = nullptr;
}

template<typename T>
void BinaryTree<T>::insertElement(const T & value, TreeNode<T> ** treenode)
{
	if (!(*treenode))
	{
		TreeNode<T> * newTreeNode = new TreeNode<T>;
		newTreeNode->value = value;
		*treenode = newTreeNode;
		return;
	}

	if (!(*treenode)->left)
	{
		insertElement(value, &(*treenode)->left); return;
	}

	if (!(*treenode)->right)
	{
		insertElement(value, &(*treenode)->right); return;
	}
}

template class BinaryTree<int>;