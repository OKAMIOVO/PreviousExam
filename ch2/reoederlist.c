/**
 * @file reoederlist.c
 * @author okami (xiaokenai@outlook.com)
 * @brief 2019 重排链表
 * @version 0.1
 * @date 2023-08-18 08:03:14
 *
 * @copyright Copyright (c) 2023
 *
 */

/*
1.先找出链表L的中间结点，为此设置两个指针p和q,指针每次走一步，指针q每次走两步，当指针q到达链
尾时，指针p正好在链表的中间结点；2.然后将L的后半段结点原地逆置。3.从单链表前后两段中依次各取一
个结点，按要求重排。

第1步找中间结点的时间复杂度为O(n),
第2步逆置的时间复杂度为O(n),
第3步合并链表的时间复杂度为O(n),
所以该算法的时间复杂度为O(n) 空间复杂度O(1)
*/

#include "ch2.h"
#include "commonstruct.h"
#include "stdio.h"
#include "stdtypedef.h"

// 寻找链表中间节点(快慢指针)
LNode* middleNode(LNode* head) {
    LNode* slow = head;
    LNode* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// 反转链表
LNode* reverseList(LNode* head) {
    LNode* prev = NULL;
    LNode* curr = head;
    while (curr) {
        LNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// 合并链表
void mergeList(LNode* l1, LNode* l2) {
    LNode* l1_tmp;
    LNode* l2_tmp;
    while (l1 != NULL && l2 != NULL) {
        l1_tmp = l1->next;
        l2_tmp = l2->next;

        l1->next = l2;
        l1 = l1_tmp;

        l2->next = l1;
        l2 = l2_tmp;
    }
}

void reorderList(LinkList head) {
    if (head == NULL) {
        return;
    }
    LNode* mid = middleNode(head);
    LinkList l1 = head;
    LinkList l2 = mid->next;
    mid->next = NULL;
    l2 = reverseList(l2);
    mergeList(l1, l2);
}

void ReordListEx(){
    LinkList L;
    Init_List(&L);
    Link_insert(&L,1,1);
    Link_insert(&L,2,2);
    Link_insert(&L,3,3);
    Link_insert(&L,4,4);
    Link_insert(&L,5,5);

    reorderList(L);
    LinkList P;
    for (P = L; P != NULL; P = P->next) {
        printf("data = %d\n", P->data);
    }
}