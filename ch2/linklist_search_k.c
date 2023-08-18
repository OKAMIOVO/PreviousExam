/**
 * @file linklist_search_k.c
 * @author okami (xiaokenai@outlook.com)
 * @brief 2009 寻找链表的倒数第k个节点 双指针后移
 * @version 0.1
 * @date 2023-08-17 09:41:39
 *
 * @copyright Copyright (c) 2023
 *
 */

/*通过链表的一次遍历，找到倒数第k个结点的位
置。算法的基本设计思想是：定义两个指针变量P和q，初始时均指向头结点的下一个结点（链
表的第一个结点），P指针沿链表移动：当P指针移动到第k个结点时，q指针开始与P指针同
步移动：当P指针移动到最后一个结点时，q指针所指示结点为倒数第k个结点。以上过程对链
表仅进行一遍扫描。*/

/*
算法的详细实现步骤
1.count=0,p和q指向链表表头结点的下一个结点。
2.若p为空，转5。
3.若count等于k,则g指向下一个结点：否则，count=count+1.
4.p指向下一个结点，转2。
5.若count等于k,则查找成功，输出该结点的data域的值，返回l:否则，说明k值超过了线性表的长度，查找失败，返回0。
*/

#include "ch2.h"
#include "commonstruct.h"
#include "stdio.h"
#include "stdtypedef.h"


int Search_k(LinkList list, int k) {
    // 查找链表list倒数第k个节点，并输出该节点data域的值
    LNode *p = list->next, *q = list->next; // 指针p、q指示低于个节点
    int count = 0;
    while (p != NULL) { // 遍历链表直到最后一个节点
        if (count < k) {
            count++; // 计数，若count<k只移动p
        } else {
            q = q->next;
        }
        p = p->next;
    }
    if (count < k) { // 查找失败返回0
        return 0;
    } else { // 查找成功
        printf("data = %d\n", q->data);
        return 1;
    }
}

void ExampleProcedure(){
    LinkList L;
    InitList(&L);
    ListInsert(L, 1, 1);
    ListInsert(L, 2, 2);
    ListInsert(L, 3, 3);
    ListInsert(L, 4, 4);
    ListInsert(L, 5, 5);
    ListInsert(L, 6, 6);

    Search_k(L,1);
}

/* 时间复杂度O(n)  其中 n 为链表的长度。需要两次遍历。
空间复杂度O(1)
*/