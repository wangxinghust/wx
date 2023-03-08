package org.wx.problems;

import java.util.HashSet;
import java.util.Set;

/**
 * 764. Largest Plus Sign
 */
public class Solution0764 {
    public static void main(String[] args) {
        Solution0764 solution = new Solution0764();
        int ans = solution.orderOfLargestPlusSign(5, new int[][]{{4, 2}});
        System.out.println(ans);
    }

    public int orderOfLargestPlusSign(int n, int[][] mines) {
        // mines的处理比较有意思，或者直接建个数组，用于标记mines，有雷为1即可。
        Set<Integer> banned = new HashSet<>();
        for (int[] mine : mines) {
            banned.add(mine[0] * n + mine[1]);
        }

        int[][] dp = new int[n][n];
        int count = 0;
        for (int i = 0; i < n; i++) {
            // 此处的count=0不可少，因为遍历第二行时，count未初始化的话会导致计算不准确
            count = 0;
            for (int j = 0; j < n; j++) {
                count = banned.contains(i * n + j) ? 0 : count + 1;
                dp[i][j] = count;
            }
            count = 0;
            for (int j = n - 1; j >= 0; j--) {
                count = banned.contains(i * n + j) ? 0 : count + 1;
                dp[i][j] = Math.min(dp[i][j], count);
            }
        }
        int ans = 0;
        for (int j = 0; j < n; j++) {
            count = 0;
            for (int i = 0; i < n; i++) {
                count = banned.contains(i * n + j) ? 0 : count + 1;
                dp[i][j] = Math.min(dp[i][j], count);
            }
            count = 0;
            for (int i = n - 1; i >= 0; i--) {
                count = banned.contains(i * n + j) ? 0 : count + 1;
                dp[i][j] = Math.min(dp[i][j], count);
                ans = Math.max(dp[i][j], ans);
            }
        }
        return ans;
    }
}
