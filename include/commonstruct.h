#ifndef __COMMONSTRUCT_H__
#define __COMMONSTRUCT_H__

#include "stdtypedef.h"

void heap_sort(int arr[], int len);
void HeapSort(int A[], int len);
void HeapSortEx();
void InitList(LinkList* L);
bool Empty(LinkList L);
bool ListInsert(LinkList L, int i, int e);
bool ListDelete(LinkList L, int i, int* e);
LNode *GetElem(LinkList L,int i);
LNode* LocateElem(LinkList L,int e);
int LinkListLength(LinkList L);
// 不带头节点
void Init_List(LinkList* L);
bool List_Empty(LinkList L);
void Link_insert(LinkList* L, int n, int e);
void Link_delete(LinkList* L, int n, int* e);

#endif
