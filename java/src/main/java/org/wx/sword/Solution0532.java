package org.wx.sword;

/**
 * 解法很多
 * 1. 哈希
 * 2. 位运算（异或）
 * 3. 数学，求和后减原数组
 */
public class Solution0532 {
    public int missingNumber(int[] nums) {
        int xor = 0;
        int n = nums.length + 1;
        for (int i = 0; i < n - 1; i++) {
            xor ^= nums[i];
        }
        for (int i = 0; i <= n - 1; i++) {
            xor ^= i;
        }
        return xor;
    }
}
