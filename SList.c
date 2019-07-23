//函数声明
#ifndef _SLIST_H_
#define _SLIST_H_
 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
 
 
// 无头单向非循环链表增删查改实现 
 
typedef int SLTDataType;
 
typedef struct SListNode{
	SLTDataType data;
	struct SListNode*next;
 
}SListNode;
 
typedef struct SList{
	SListNode* head;
}SList;
 
void SListInit(SList* plist);
void SListDestory(SList* plist);
SListNode* BuySListNode(SLTDataType x);
void SListPushFront(SList* plist, SLTDataType x);
void SListPopFront(SList* plist);
SListNode* SListFind(SList* plist, SLTDataType x);
// 在pos的后面进行插入
void SListInsertAfter(SList* pos, SLTDataType x);
void SListEraseAfter(SList* pos);
void SListRemove(SList* plist, SLTDataType x);
void SListPrint(SList* plist);
 
 
#endif/*_SLIST_H_*/

//函数实现
#include"SList.h"
#include<stdio.h>
 
 
SListNode* BuySListNode(SLTDataType x)//创建结点
{
	SListNode* res = 
	res = (SListNode*)malloc(sizeof(SListNode));
	if (res == NULL)
	{
		printf("创建结点失败");
		return NULL;
	}
	res->data = x;
	res->next = NULL;
	return res;
}
 
void SListInit(SList* plist)
{
	plist->head=NULL;
}
 
void SListPushFront(SList* plist, SLTDataType x)//头插
{
	SListNode* tmp = BuySListNode(x); 
	if (tmp != NULL)
	{
		tmp->next = plist->head;
		plist->head = tmp;
	}
}
void SListPopFront(SList* plist)//头删
{
	if (NULL != plist->head)
	{
		SListNode* pt = plist->head;
		plist->head = pt->next;
		free(pt);
	}
}
 
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	SListNode* tmp = BuySListNode(x);
	tmp->next = pos->next;
	pos->next = tmp;
}
void SListEraseAfter(SListNode* pos)//删除pos+1位置结点
{
	SListNode* tmp = pos->next;
	pos->next = pos->next->next;
	free(tmp);
}
 
SListNode* SListFind(SList* plist, SLTDataType x)//查询指定值
{
	SListNode* tmp=plist->head;
	while (tmp!= NULL)
	{
		if (tmp->data == x)
			return tmp;
		else
			tmp = tmp->next;
	}
	return NULL;
}
 
void SListRemove(SList* plist, SLTDataType x)//删除值为x的结点
{
	while (plist->head != NULL&&plist->head->data == x)
	{
		SListPopFront(plist);
	}
	if (plist->head == NULL)
	{
		return;
	}
	SListNode* ph = plist->head;
	SListNode* pt = ph->next;
	while (NULL != pt)
	{
		if (pt->data == x)
		{
			pt = pt->next;
			SListEraseAfter(ph);
			ph->next = pt;
			continue;
		}
		pt = pt->next;
		ph = ph->next;
	}
 
}
		
void SListPrint(SList* plist)
{
	SListNode* pt = plist->head;
	while (NULL != pt)
	{
		printf("%d->", pt->data);
		pt = pt->next;
	}
	printf("\n");
}
 
void SListDestory(SList* plist)
{
	if (plist->head != NULL)
	{
		SListNode*pt = plist->head;
		while (pt!=NULL)
		{
			SListNode* t=pt;
			pt = pt->next;
			free(t);
		}
		plist->head = NULL;
	}
}

//测试函数
#include"SList.h"
 
int main()
{
	SList test;
 
	SListInit(&test);
 
	SListPushFront(&test, 1);
	SListPushFront(&test, 2);
	SListPushFront(&test, 3);
	SListNode* tmp = test.head->next->next;
	SListInsertAfter(tmp, 4);
	SListInsertAfter(tmp, 4);
	SListInsertAfter(tmp, 5);
	SListInsertAfter(tmp, 6);
    //打印
    SListPrint(&test);
	SListRemove(&test, 6);
	SListPrint(&test);
	//摧毁
	SListDestory(&test);
 
	system("pause");
	return 0;
}

