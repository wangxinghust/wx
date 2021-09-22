package org.wx.problems;

/**
 * 231. Power of Two
 */
public class Solution0231 {
    /**
     * 官方方法一 二进制判断，取最低位1，n&(n-1)用于将最低位1置0，n&(-n)用于取出最低位1
     */
    public boolean isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }

    public boolean isPowerOfTwo2(int n) {
        return n > 0 && (n & (-n)) == n;
    }

    /**
     * 官方方法二，获取int的最大2的幂，然后判断n是否是约数
     */
    static final int BIG = 1 << 30;

    public boolean isPowerOfTwo3(int n) {
        return n > 0 && BIG % n == 0;
    }
}
