/**
 * @file setparation.c
 * @author okami (xiaokenai@outlook.com)
 * @brief 2016 划分数组
 * @version 0.1
 * @date 2023-08-21 16:06:24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "stdio.h"
#include "ch8.h"
#include "commonstruct.h"
#include "stdtypedef.h"

/*
满足："元素个数的差距最小"且"元素之和的差距最大"
将最小的(n/2)个(向下取整)元素一起，其他的一起即可。
"快排的部分选择结果"
*/

int setParation(int a[],int n){
    int pivoykey,low = 0,low0 = 0,high = n-1,high0 = n-1,flag = 1,k = n/2,i;
    int s1 = 0,s2 = 0;

    while(flag){
        pivoykey = a[low];      // 选择枢轴
        while(low < high){
            while(low < high && a[high] >= pivoykey) --high;
            if(low != high) a[low] = a[high];
            while(low < high && a[low] <= pivoykey) ++low;
            if(low != high) a[high] = a[low];
        }
        a[low] = pivoykey;
        if(low == k-1)          // 若枢轴是第n/2个小元素，划分成功  (0开始)
        {
            flag = 0;
        }else{  // 是否继续划分
            if(low < k-1){
                low0 = ++low;
                high = high0;
            }else{
                high0 = --high;
                low = low0;
            }
            
        }
    }
    for(i = 0; i < k; i++)  s1+=a[i];
    for(i = k; i < n; i++)  s2+=a[i];
    return s2 - s1;
}

void setParationEx(){
    int a[] = {89,23,57,2,0,56,36,98,74,25,37};
    int subValue = setParation(a, 11);
    printf("subValue = %d\n",subValue);
}

/* 空间复杂度O(1),时间复杂度O(n) */
