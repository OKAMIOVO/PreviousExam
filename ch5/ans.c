/**
 * @file ans.c
 * @author okami (xiaokenai@outlook.com)
 * @brief 2017 操作数 操作符 中序遍历
 * @version 0.1
 * @date 2023-08-19 10:14:58
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "stdio.h"
#include <stdlib.h>
#include "ch5.h"
#include "commonstruct.h"
#include "stdtypedef.h"

/*
中序遍历二叉树，对于当前访问的非空结点p，则先输出”(“，
然后递归调用左子树，输出p的权值，递归调用右子树，输出”)”，
如果p是根或者叶结点则不需要输出”(”或”)”。
*/

void CreateBiTree_ans(BTree* T) {
    *T = (BTNode*)malloc(sizeof(BTNode));
    (*T)->data = "*";
    (*T)->lchild = (BTNode*)malloc(sizeof(BTNode));
    (*T)->rchild = (BTNode*)malloc(sizeof(BTNode));

    (*T)->lchild->data = "+";
    (*T)->lchild->lchild = (BTNode*)malloc(sizeof(BTNode));
    (*T)->lchild->rchild = (BTNode*)malloc(sizeof(BTNode));
    (*T)->lchild->rchild->data = "b";
    (*T)->lchild->lchild->data = "a";
    (*T)->lchild->lchild->lchild = NULL;
    (*T)->lchild->lchild->rchild = NULL;
    (*T)->lchild->rchild->lchild = NULL;
    (*T)->lchild->rchild->rchild = NULL;
    (*T)->rchild->data = "*";
    (*T)->rchild->lchild = (BTNode*)malloc(sizeof(BTNode));
    (*T)->rchild->lchild->data = "c";
    (*T)->rchild->lchild->lchild = NULL;
    (*T)->rchild->lchild->rchild = NULL;
    (*T)->rchild->rchild = (BTNode*)malloc(sizeof(BTNode));
    (*T)->rchild->rchild->data = "-";
    (*T)->rchild->rchild->rchild = (BTNode*)malloc(sizeof(BTNode));
    (*T)->rchild->rchild->lchild = NULL;
    (*T)->rchild->rchild->rchild->data = "d";
    (*T)->rchild->rchild->rchild->lchild = NULL;
    (*T)->rchild->rchild->rchild->rchild = NULL;
}

// 输出结点本身的值
void visit(BTNode* e) { printf("%s ", e->data); }

// 中序遍历
void PreOrder(BTree T) {
    // printf("T = %p\n",T);
    if (T != NULL) {
        PreOrder(T->lchild); // 递归遍历左子树
        visit(T);            // 访问根节点
        PreOrder(T->rchild); // 递归遍历右子树
    }
}

void BtreeToExp(BTree root, int deep) {
    if (root == NULL) // 空节点返回
    {
        return;
    } else if (root->lchild == NULL && root->rchild == NULL) // 叶节点
    {
        printf("%s", root->data); // 输出操作数，不加括号
    } else {
        if (deep > 1)
            printf("("); // 若有子表达式则加1层括号
        BtreeToExp(root->lchild, deep + 1);
        printf("%s", root->data); // 输出操作符
        BtreeToExp(root->rchild, deep + 1);
        if (deep > 1)
            printf(")"); //  若有子表达式则加1层括号
    }
}

void BtreeToe(BTree* root) {
    BtreeToExp(*root, 1); // 根的高度为1
}

void ansEx() {
    BTree T;
    CreateBiTree_ans(&T);
    // PreOrder(T);
    BtreeToe(&T);
}
