/**
 * @file reverse.c
 * @author okami (xiaokenai@outlook.com)
 * @brief 数组逆置 2010
 * @version 0.1
 * @date 2023-08-12 08:44:27
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "stdio.h"
#include "ch2.h"

void Reverse(char R[], int from, int to) {
    int i;
    char temp;
    for (i = 0; i < (to - from + 1) / 2; i++) {
        temp = R[from + i];
        R[from + i] = R[to - i];
        R[to - i] = temp;
    }
}

void Converse(char R[], int n, int p) {
    Reverse(R, 0, p - 1);
    Reverse(R, p, n - 1);
    Reverse(R, 0, n - 1);
}

void ConverseEx(){
    char R[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    Converse(R, 8, 3);
    for (int i = 0; i < 8; i++) {
        printf("R[%d] = %c\n", i, R[i]);
    }
}