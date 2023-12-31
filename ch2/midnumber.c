/**
 * @file midnumber.c
 * @author okami (xiaokenai@outlook.com)
 * @brief 2011求两个升序序列的中位数
 * @version 0.1
 * @date 2023-08-15 10:54:05
 *
 * @copyright Copyright (c) 2023
 *
 */

/*
 *算法的基本设计思想如下。
 *分别求两个升序序列A、B的中位数，设为a和b，求序列A、B的中位数过程如下：
 *1.若a=b，则a或b即为所求中位数，算法结束。
 *2.若a<b，则舍弃序列A中较小的一半，同时舍弃序列B中较大的一半，要求两次舍弃的
 *长度相等。
 *3.若a>b，则舍弃序列A中较大的一半，同时舍弃序列B中较小的一半，要求两次舍弃的
 *长度相等。
 *在保留的两个升序序列中，重复过程1，2，3，直到两个序列中均只含一个元素时为止，
 *小者即为所求的中位数。
 */

#include "ch2.h"
#include "stdio.h"

int M_Search(int A[], int B[], int n) {
    int s1 = 0, d1 = n - 1, m1, s2 = 0, d2 = n - 1, m2;
    // 分别表示序列A和B的首位数、末位数和中位数
    while (s1 != d1 || s2 != d2) {
        m1 = (s1 + d1) / 2;
        m2 = (s2 + d2) / 2;
        if (A[m1] == B[m2])
            return A[m1];             // 满足条件1
        if (A[m1] < B[m2]) {          // 满足条件2
            if ((s1 + d1) % 2 == 0) { // 若元素个数为奇数
                s1 = m1; // 舍弃A中间点以前的部分且保留中间点
                d2 = m2; // 舍弃B中间点以后的部分且保留中间点
            } else {     // 元素个数为偶数
                s1 = m1 + 1; // 舍弃A中间点以及中间点以前部分
                d2 = m2;     // 舍弃B中间点以后部分且保留中间点
            }
        } else {                      // 满足条件3
            if ((s2 + d2) % 2 == 0) { // 若元素个数为奇数
                d1 = m1; // 舍弃A中间点以后的部分且保留中间点
                s2 = m2; // 舍弃B中间点以前的部分且保留中间点
            } else {     // 元素个数为偶数
                d1 = m1; // 舍弃A中间点以后部分且保留中间点
                s2 = m2 + 1; // 舍弃B中间点及中间点以前部分
            }
        }
    }
    return A[s1] < B[s2] ? A[s1] : B[s2];
}

void MidSearchEx(){
    int A[] = {11,13,15,17,19};
    int B[] = {2,4,6,8,20};
    int mid = M_Search(A,B,5);
    printf("mid number = %d\n",mid);
}
