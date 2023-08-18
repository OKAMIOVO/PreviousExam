/**
 * @file mindistance.c
 * @author okami (xiaokenai@outlook.com)
 * @brief 2020 计算三元组的最小距离 滑动窗口
 * @version 0.1
 * @date 2023-08-16 13:47:05
 *
 * @copyright Copyright (c) 2023
 *
 */

/*算法整体的思路是开始得出三个集合各取第一个元素组成的三
元组的最小距离min_D，并额外申请三个变量（分别为min_sl，min_s2,min_s3
存储对应的三元组的元素值。接下来每次只移动三个元素中最小元素的下标，
计算新的距离D与之前得到的最小距离min_D比较，若D<min_D则更新最小距离
同时更新min_sl,min_s2,min_s3的值。直到某个下标超出对应集合大小，算
法结束，此时min_D即为最小距离，（min_slmin_s2,min_s3）即为对应三元组*/

#include "ch2.h"
#include "stdio.h"
#include <stdlib.h>

// n1 n2 n3分别是s1 s2 s3长度
void minDis(int s1[], int s2[], int s3[], int n1, int n2, int n3) {
    int i = 0, j = 0, k = 0; // i,j,k分别是s1,s2,s3的下标
    int min_D = 65535, min_s1, min_s2, min_s3; // 初始化结果变量
    while (i < n1 && j < n2 && k < n3) {
        int D = abs(s1[i] - s2[j]) + abs(s2[j] - s3[k]) +
                abs(s3[k] - s1[i]); // 更新D
        if (D < min_D) { // 此时D小于此前统计min_D，则更新相关结果变量
            min_D = D;
            min_s1 = s1[i];
            min_s2 = s2[j];
            min_s3 = s3[k];
        }
        if (s1[i] < s2[j] && s1[i] < s3[k]) { // 若s1[i]是最小的，则对应下标i++
            ++i;
        } else if (s2[j] < s1[i] &&
                   s2[j] < s3[k]) { // 若s2[j]是最小的，则对应下标j++
            ++j;
        } else { // 若s3[k]是最小的，则对应下标k++
            ++k;
        }
    }
    printf("D = %d,(%d,%d,%d)\n", min_D, min_s1, min_s2, min_s3);
}

void minDisEx(){
    int s1[] = {-1,0,9};
    int s2[] = {-25,-10,10,11};
    int s3[] = {2,9,17,30,41};
    minDis(s1,s2,s3,3,4,5);
}
