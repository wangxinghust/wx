package org.wx.problems;

/**
 * 279. 完全平方数
 */
public class Solution0279 {
    // 贪心是错的，比如12=4+4+4，而不是12=9+1+1+1
    public int numSquares(int n) {
        int ans = 0;
        do {
            System.out.println(n);
            int x = (int) Math.sqrt(n * 1.0);
            n -= x * x;
            ans++;
        } while (n != 0);
        return ans;
    }

    // 官解一：动态规划
    public int numSquares2(int n) {
        int[] f = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            int minn = Integer.MAX_VALUE;
            for (int j = 1; j * j <= i; j++) {
                minn = Math.min(minn, f[i - j * j]);
            }
            f[i] = minn + 1;
        }
        return f[n];
    }

    // 官解二：数学定理
}
