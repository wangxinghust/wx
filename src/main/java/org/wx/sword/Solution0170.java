package org.wx.sword;

/**
 * 剑指offer上该题重点在大树打印，重点是字符串自增实现
 */
public class Solution0170 {
    public int[] printNumbers(int n) {
        int end = (int) Math.pow(10, n) - 1;
        int[] res = new int[end];
        for (int i = 0; i < end; i++)
            res[i] = i + 1;
        return res;
    }
}
