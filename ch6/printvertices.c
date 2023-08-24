/**
 * @file printvertices.c
 * @author okami (xiaokenai@outlook.com)
 * @brief 2023 有向图出度、入度
 * @version 0.1
 * @date 2023-08-24 10:54:07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ch6.h"
#include "commonstruct.h"

int printVertices(MGraph G){
    int indegrees[G.numVertices];
    int outdegrees[G.numVertices];

    memset(indegrees, 0, sizeof(indegrees));
    memset(outdegrees, 0, sizeof(outdegrees));

    // 遍历有向图统计所有点的出度和入度
    for(int i = 0; i < G.numVertices; i++){
        for(int j = 0; j < G.numVertices; j++){
            outdegrees[i] += G.Edge[i][j];
            indegrees[j] += G.Edge[i][j];
        }
    }

    int count = 0;
    // 遍历indegrees和outdegrees数组统计出度大于入度的顶点
    for(int i = 0; i < G.numVertices; i++){
        if(outdegrees[i] > indegrees[i]){
            printf("K顶点：%c\n",G.VerticesList[i]);
            count++;
        }
    }
    return count;
}

void printVerticesEx(){
    MGraph G;
    CreateMGraphDirect(&G);
    ShowMGraph(G);
    int count = printVertices(G);
    printf("K顶点个数：%d\n",count);
}

/* 空间O(n)，时间O(n^2) */