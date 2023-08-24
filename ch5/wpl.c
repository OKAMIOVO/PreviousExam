/**
 * @file wpl.c
 * @author okami (xiaokenai@outlook.com)
 * @brief 2014 带权路径长度
 * @version 0.1
 * @date 2023-08-18 13:43:20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*
算法的基本设计思想。
1.基于先序递归遍历的算法思想是用一个static变量记录wpl,把每个结点的深度作为
递归函数的一个参数传递，算法步骤如下：
a.若该结点是叶结点，则变量wP1加上该结点的深度与权值之积。
b.若该结点是非叶结点，则左子树不为空时，对左子树调用递归算法，右子树不为空，
对右子树调用递归算法，深度参数均为本结点的深度参数加1.
最后返回计算出的wp1即可。
2.基于层次遍历的算法思想是使用队列进行层次遍历，并记录当前的层数：
a.当遍历到叶结点时，累计wpl.
b.当遍历到非叶结点时，把该结点的子树加入队列。
c.当某结点为该层的最后一个结点时，层数自增1.
队列空时遍历结束，返回wp1。
*/

#include "ch5.h"
#include "commonstruct.h"
#include "stdio.h"
#include "stdtypedef.h"
#include <stdlib.h>

#define MaxSize 100     // 设置队列的最大容量

void CreateBiTree(BiTree* T){
    *T=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->data=8;
    (*T)->lchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->rchild=(BiTNode*)malloc(sizeof(BiTNode));
  
    (*T)->lchild->data=12;
    (*T)->lchild->lchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->lchild->rchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->lchild->rchild=NULL;
    (*T)->lchild->lchild=NULL;
    (*T)->rchild->data=2;
    (*T)->rchild->lchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->rchild->lchild->data=6;
    (*T)->rchild->lchild->lchild=NULL;
    (*T)->rchild->lchild->rchild=NULL;
    (*T)->rchild->rchild=(BiTNode*)malloc(sizeof(BiTNode));
    (*T)->rchild->rchild->data=4;
    (*T)->rchild->rchild->lchild=NULL;
    (*T)->rchild->rchild->rchild=NULL;
   
}

// 先序遍历
int wpl_PreOrder(BiTree root,int deep){
    static int wpl = 0;     // 定义变量存储wpl
    if(root->lchild == NULL && root->rchild == NULL)    // 若为叶节点，则累计wpl
        wpl+=deep*root->data;
    if(root->lchild != NULL)                            // 若左子树不空，则对左子树递归遍历
        wpl_PreOrder(root->lchild, deep+1);
    if(root->rchild != NULL)                            // 若右子树不空，则对右子树递归遍历
        wpl_PreOrder(root->rchild, deep+1);
    return wpl;
}

// 基于先序遍历的算法
int WPL(BiTree root){
    return wpl_PreOrder(root, 0);
}

// 基于层序遍历的算法
int wpl_LevelOrder(BiTree root){
    BiTree q[MaxSize];          // 声明队列，end1为头指针，end2为尾指针
    int end1,end2;              // 队列最多容纳MaxSize-1个元素
    end1 = end2 = 0;            // 头指针指向队头元素，尾指针指向队尾的后一个元素
    int wpl = 0, deep = 0;      // 初始化wpl和深度
    BiTree lastNode;            // lastNode用来记录当前层的最后一个节点
    BiTree newlastNode;         // newlastNode用来记录下一层的最后一个节点
    lastNode = root;            // lastNode初始化为根节点
    newlastNode = NULL;         // newlastNode初始化为空
    q[end2++] = root;           // 根节点入队
    while(end1 != end2){        // 层次遍历，若队列不空则循环
        BiTree t = q[end1++];   // 拿出队列中的头一个元素
        if(t->lchild == NULL && t->rchild == NULL){
            wpl+=deep*t->data;
        }                       // 若为叶节点，则统计wpl
        if(t->lchild != NULL){  // 若非叶节点，则让左节点入队
            q[end2++] = t->lchild;
            newlastNode = t->lchild;
        }                       // 并设下一层的最后一个节点为该节点的左节点
        if(t->rchild != NULL){  // 处理叶节点
            q[end2++] = t->rchild;
            newlastNode = t->rchild;
        }
        if(t == lastNode){      // 若该节点为本层最后一个节点，则更新lastNode
            lastNode = newlastNode;
            deep+=1;            // 层数加1
        }
    }
    return wpl;                 // 返回wpl
}

void wplEx(){
    BiTree T;
    CreateBiTree(&T);
    int wplVal =  WPL(T);
    printf("递归wpl = %d\n",wplVal);
    int levelwplVal = wpl_LevelOrder(T);
    printf("层序wpl = %d\n",levelwplVal);
}


/* 
注意：当static关键字用于代码块内部的变量的声明时，用于修改变量的存储类型，即从
自动变量修改为静态变量，但变量的链接属性和作用域不受影响，用这种方式声明的变量在程序
执行之前创建，并在程序的整个执行期间一直存在，而不是每次在代码块开始执行时创建，在代
码块执行完毕后销毁。也就是说，它保持局部变量内容的持久。静态局部变量的生存期虽然为整
个源程序，但其作用域仍与局部变量相同，即只能在定义该变量的函数内使用该变量。退出该函
数后，尽管该变量还继续存在，但不能使用它。读者在该阶段对此只做了解即可，有兴趣的请查
阅相关资料。
 */