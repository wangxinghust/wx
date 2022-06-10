package org.wx.sword;

public class Solution0150 {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int ret = 0;
        while (n != 0) {
            n &= n - 1;
            ret++;
        }
        return ret;
    }
}
