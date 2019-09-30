#include "BTree.h"

BTNode* BinaryTreeCreate(BTDataType* a)
{

}


//前序递归遍历
void BinaryTreePrevOrder(BTNode *root) 
{
	if (root != NULL)
	{
		printf("%c", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}
//中序递归遍历
void BinaryTInPrevOrder(BTNode *root)
{
	if (root != NULL)
	{
		BinaryTreePrevOrder(root->_left);
		printf("%c", root->_data);
		BinaryTreePrevOrder(root->_right);
	}
}
//后序递归遍历
void BinaryPostPrevOrder(BTNode *root)
{
	if (root != NULL)
	{
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
		printf("%c", root->_data);
	}
}
//前序非递归遍历（栈）
void BinaryTreePrevOrderNonR(BTNode* root)
{

}
//中序非递归遍历（栈）
void BinaryTreeInOrderNonR(BTNode* root)
{

}
//后序非递归遍历（栈）
void BinaryTreePostOrderNonR(BTNode* root)
{

}
