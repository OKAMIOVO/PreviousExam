/**
 * @file miniumelem.c
 * @author okami (xiaokenai@outlook.com)
 * @brief 2018寻找缺失的最小正整数 https://leetcode.cn/problems/first-missing-positive/solutions/304743/que-shi-de-di-yi-ge-zheng-shu-by-leetcode-solution/ (相似度100%)
 * @version 0.1
 * @date 2023-08-16 10:35:18
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "ch2.h"
#include "stdio.h"
#include <stdlib.h>

int firstMissingPositive(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] <= 0) {
            nums[i] = numsSize + 1;
        }
    }
    for (int i = 0; i < numsSize; ++i) {
        int num = abs(nums[i]);
        if (num <= numsSize) {
            nums[num - 1] = -abs(nums[num - 1]);
        }
    }
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] > 0) {
            return i + 1;
        }
    }
    return numsSize + 1;
}

void firstMissingPositiveEx(){
    int minInterNums1[] = {-5,3,2,3};
    int minInterNums2[] = {1,2,3};
    int minnum = firstMissingPositive(minInterNums2,4);
    #if (!defined MINUM)
    printf("minum = %d\n",minnum);
    #endif
}

// 时间复杂度：O(N)，其中 N 是数组的长度。
// 空间复杂度：O(1)。

// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/first-missing-positive/solutions/304743/que-shi-de-di-yi-ge-zheng-shu-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。