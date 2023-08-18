/**
 * @file intersectlist.c
 * @author okami (xiaokenai@outlook.com)
 * @brief 2012 相交链表 双指针 找共同后缀
 * @version 0.1
 * @date 2023-08-17 13:43:56
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*
本题的结构体是单链表，采用双指针法。用指针p、q分别扫描str1和str2,当p、q指
向同一个地址时，即找到共同后缀的起始位置。

算法的基本设计思想如下：
1.分别求出str1和str2所指的两个链表的长度m和n.
2.将两个链表以表尾对齐：令指针p、q分别指向str1和str2的头结点，若m≥n,则
指针p先走，使p指向链表中的第m-n+1个结点：若m<n,则使g指向链表中的第
n-m+1个结点，即使指针p和g所指的结点到表尾的长度相等。
3.反复将指针p和q同步向后移动，当P、q指向同一位置时停止，即为共同后缀的起始
位置，算法结束。
*/

#include "ch2.h"
#include "commonstruct.h"
#include "stdio.h"
#include "stdtypedef.h"

// 找共同后缀的起始地址
LNode* find_addr(LNode *str1,LNode *str2){
    int m,n;
    LNode *p,*q;
    m = LinkListLength(str1);   // str1长度
    n = LinkListLength(str2);   // str2长度
    for(p = str1; m > n; m--){      // 若m>n,使p指向链表中的第m-n+1个节点
        p = p->next;
    }
    for(q = str2; m < n; n--){      // 若m<n,使q指向链表中的第n-m+1个节点
        q = q->next;
    }
    while (p->next != NULL && p->next != q->next) {     // 指针p和q同步向后移
        p = p->next;
        q = q->next;
    }
    return p->next;         // 返回共同后缀的起始地址
}

void IntersectExample(){
    LinkList str1;
    LinkList str2;

    InitList(&str1);
    InitList(&str2);

    ListInsert(str1, 1, 4);
    ListInsert(str1, 2, 1);
    ListInsert(str1, 3, 8);
    ListInsert(str1, 4, 4);
    ListInsert(str1, 5, 5);

    ListInsert(str2, 1, 5);
    ListInsert(str2, 2, 6);
    ListInsert(str2, 3, 1);
    ListInsert(str2, 4, 8);
    ListInsert(str2, 5, 4);
    ListInsert(str2, 6, 5);

    //LNode *s = find_addr(str1,str2);
    //printf("Intersected at %d\n",s->data);

    // 此算法相交链表不好实现，理解算法即可
}

/*
时间复杂度O(len1+len2)或O(max(len1,len2))，其中len1,len2分别为两个链表的长度
*/