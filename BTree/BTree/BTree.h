#ifndef _BTREE_H_
#define _BTREE_H_

#include<stdio.h>
#include<windows.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode *_left;
	struct BinaryTreeNode *_right;
}BTNode;

//通过前序遍历的数组,例"ABD##E#H##CF##G##",构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a); 
void BinaryTreeDestory(BTNode** root);
int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelKSize(BTNode* root, int k);
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// 递归遍历
void BinaryTreePrevOrder(BTNode* root); //前序
void BinaryTreeInOrder(BTNode* root);//中序
void BinaryTreePostOrder(BTNode* root);//后序
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root); 
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);
void BinaryTreePrevOrderNonR(BTNode* root);
void BinaryTreeInOrderNonR(BTNode* root);
void BinaryTreePostOrderNonR(BTNode* root);
void TestBinaryTree();

#endif  /*_BTREE_H_*/