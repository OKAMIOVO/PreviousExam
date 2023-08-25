/**
 * @file judgebst.c
 * @author okami (xiaokenai@outlook.com)
 * @brief 2022 判断二叉搜索树
 * @version 0.1
 * @date 2023-08-24 12:51:57
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "ch5.h"
#include "commonstruct.h"

#include <stdio.h>
#include <stdlib.h>

bool judgeInorderBST(SqList bt, int k, int* val) { // 初始调用时k的值是0
    if (k < bt.length && bt.data[k] != -1) {
        if (!judgeInorderBST(bt, 2 * k + 1, val)) // 递归调用左子树
            return false;                         // 左子树不符合定义
        if (bt.data[k] <= *val)                   // 当前节点
            return false;  // 前驱大于当前节点，不符合定义
        *val = bt.data[k]; // 更新前驱val
        if (!judgeInorderBST(bt, 2 * k + 2, val)) // 递归调用右子树
            return false;                         // 右子树不符合定义
    }
    return true; // 根下标为k的子树符合定义
}

void judgeBstEx() {
    SqList bt;
    int val = 0;
    InitSeqList(&bt);
    SeqListInsert(&bt, 1, 40);
    SeqListInsert(&bt, 2, 50);
    SeqListInsert(&bt, 3, 60);
    SeqListInsert(&bt, 4, -1);
    SeqListInsert(&bt, 5, 30);
    SeqListInsert(&bt, 6, -1);
    SeqListInsert(&bt, 7, 80);
    SeqListInsert(&bt, 8, -1);
    SeqListInsert(&bt, 9, -1);
    SeqListInsert(&bt, 10, 27);
    bool isBST = judgeInorderBST(bt, 0, &val);
    if (isBST == true)
        printf("BST\n");
    else
        printf("NOT BST");
}