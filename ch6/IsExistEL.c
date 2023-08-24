/**
 * @file IsExistEL.c
 * @author okami (xiaokenai@outlook.com)
 * @brief 2021 欧拉路径
 * @version 0.1
 * @date 2023-08-21 13:35:28
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "stdio.h"
#include <stdlib.h>
#include "ch6.h"
#include "commonstruct.h"


int IsExistEL(MGraph G) {
    // 采用邻接矩阵存储，判断图是否存在EL路径
    int degree, i, j, count = 0;
    for (i = 0; i < G.numVertices; i++) {
        degree = 0;
        for (j = 0; j < G.numVertices; j++) {
            degree += G.Edge[i][j]; // 依次计算各个顶点的度
        }
        printf("顶点%d的度=%d\n", i, degree);
        if (degree % 2 != 0)
            count++; // 对度为奇数的顶点计数
    }
    if (count == 0 || count == 2) {
        return 1; // 存在欧拉路径
    } else {
        return 0; // 不存在欧拉路径
    }
}

void IsExistELEx() {
    MGraph G;
    CreateMGraph(&G);
    ShowMGraph(G);
    int isExistEl = IsExistEL(G);
    if (isExistEl == 1)
        printf("存在El\n");
    else
        printf("不存在El\n");
}
