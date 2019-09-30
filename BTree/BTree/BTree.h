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

//ͨ��ǰ�����������,��"ABD##E#H##CF##G##",����������
BTNode* BinaryTreeCreate(BTDataType* a); 
void BinaryTreeDestory(BTNode** root);
int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelKSize(BTNode* root, int k);
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// �ݹ����
void BinaryTreePrevOrder(BTNode* root); //ǰ��
void BinaryTreeInOrder(BTNode* root);//����
void BinaryTreePostOrder(BTNode* root);//����
// �������
void BinaryTreeLevelOrder(BTNode* root); 
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root);
void BinaryTreePrevOrderNonR(BTNode* root);
void BinaryTreeInOrderNonR(BTNode* root);
void BinaryTreePostOrderNonR(BTNode* root);
void TestBinaryTree();

#endif  /*_BTREE_H_*/