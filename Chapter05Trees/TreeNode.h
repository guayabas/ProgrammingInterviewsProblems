#pragma once

template<typename T>
class TreeNode
{
public:
	TreeNode(); ~TreeNode();

	TreeNode * right;
	TreeNode * left;
	T value;
};