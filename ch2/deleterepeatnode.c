/**
 * @file deleterepeatnode.c
 * @author okami (xiaokenai@outlook.com)
 * @brief 2015 删除重复节点
 * @version 0.1
 * @date 2023-08-17 15:20:20
 *
 * @copyright Copyright (c) 2023
 *
 */

/*
1.算法的核心思想是用空间换时间。使用辅助数组记录链表中已出现的数值，从而只需对链
表进行一趟扫描。
2.因为|data|≤n,故辅助数组q的大小为n+1,各元素的初值均为0。依次扫描链表中的
各结点，同时检查g[Idatal]的值，若为0则保留该结点，并令q[ldatal]=1;否则
将该结点从链表中别除。
*/

#include "ch2.h"
#include "commonstruct.h"
#include "stdio.h"
#include "stdtypedef.h"

#include <stdlib.h>

void func(LinkList h, int n) {
    LinkList p = h, r;
    int *q, m;
    q = (int*)malloc(sizeof(int) * (n + 1)); // 申请n+1个位置的辅助空间
    for (int i = 0; i < n + 1; i++) {        // 数组元素初值置0
        *(q + i) = 0;
    }
    while (p->next != NULL) {
        m = p->next->data > 0 ? p->next->data : -p->next->data;
        if (*(q + m) == 0) { // 判断该节点的data是否已经出现过
            *(q + m) = 1;    // 首次出现
            p = p->next;     // 保留
        } else {             // 重复出现
            r = p->next;
            p->next = r->next;
            free(r);
        }
    }
    free(q);
}

void DelReeatNodeExample() {
    LinkList h;
    InitList(&h);
    ListInsert(h, 1, 21);
    ListInsert(h, 2, -15);
    ListInsert(h, 3, -15);
    ListInsert(h, 4, -7);
    ListInsert(h, 5, 15);

    func(h, 21);

    // for (h = h->next; h != NULL; h = h->next) {
    //     printf("redata = %d\n",h->data);
    // }

    for (; h->next != NULL; h = h->next) {
        printf("redata = %d\n",h->next->data);
    }
}

// 时间复杂度O(m) m个整数 空间复杂度O(n)
