/**
 * @file mainelem.c
 * @author okami (xiaokenai@outlook.com)
 * @brief 2013寻找数组主元素 https://leetcode.cn/problems/find-majority-element-lcci/description/ (相似度100%)
 * 摩尔投票法
 * @version 0.1
 * @date 2023-08-16 09:34:42
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "ch2.h"
#include "stdio.h"

int majorityElement(int* nums, int numsSize) {
    int candidate = -1;
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (count == 0) {
            candidate = nums[i];
        }
        if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }
    count = 0;
    int length = numsSize;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate) {
            count++;
        }
    }
    return count * 2 > length ? candidate : -1;
}

void MajorityElemEx(){
    int majority1[] = {0,5,5,3,5,7,5,5};
    int majority2[] = {0,5,5,3,5,1,5,7};
    // int majorityelem = majorityElement(majority1,8);
    int majorityelem = majorityElement(majority2,8);
    if(majorityelem != -1){
        printf("majorityElem = %d\n",majorityelem);
    }else{
        printf("majorityElem not exist!\n");
    }
}

// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/find-majority-element-lcci/solutions/865863/zhu-yao-yuan-su-by-leetcode-solution-xr1p/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
