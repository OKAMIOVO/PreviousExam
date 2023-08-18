#ifndef __STDTYPEDEF_H__
#define __STDTYPEDEF_H__

#define bool int
#define true 1
#define false 0

typedef struct LNode {
    int data;
    struct LNode* next;
} LNode, *LinkList;

#endif
