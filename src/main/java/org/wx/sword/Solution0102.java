package org.wx.sword;

public class Solution0102 {
    public int numWays(int n) {
        int cur = 1, nxt = 1;
        for (int i = 0; i < n; i++) {
            int tmp = nxt;
            nxt = (cur + nxt) % 1000000007;
            cur = tmp;
        }
        return cur;
    }
}
