#include "BTree.h"

BTNode* BinaryTreeCreate(BTDataType* a)
{

}


//ǰ��ݹ����
void BinaryTreePrevOrder(BTNode *root) 
{
	if (root != NULL)
	{
		printf("%c", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}
//����ݹ����
void BinaryTInPrevOrder(BTNode *root)
{
	if (root != NULL)
	{
		BinaryTreePrevOrder(root->_left);
		printf("%c", root->_data);
		BinaryTreePrevOrder(root->_right);
	}
}
//����ݹ����
void BinaryPostPrevOrder(BTNode *root)
{
	if (root != NULL)
	{
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
		printf("%c", root->_data);
	}
}
//ǰ��ǵݹ������ջ��
void BinaryTreePrevOrderNonR(BTNode* root)
{

}
//����ǵݹ������ջ��
void BinaryTreeInOrderNonR(BTNode* root)
{

}
//����ǵݹ������ջ��
void BinaryTreePostOrderNonR(BTNode* root)
{

}
