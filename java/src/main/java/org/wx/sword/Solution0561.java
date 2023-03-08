package org.wx.sword;

/**
 * 位运算解
 * 在一位数字不同的基础上，通过对异或结果找1，然后分组，就找到两个不同的数了
 */
public class Solution0561 {
    public int[] singleNumbers(int[] nums) {
        int ret = 0;
        for (int n : nums) {
            ret ^= n;
        }
        int div = 1;
        while ((div & ret) == 0) {
            div <<= 1;
        }
        int a = 0, b = 0;
        for (int n : nums) {
            if ((div & n) != 0) {
                a ^= n;
            } else {
                b ^= n;
            }
        }
        return new int[]{a, b};
    }
}
