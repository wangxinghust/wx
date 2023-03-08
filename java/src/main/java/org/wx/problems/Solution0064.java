package org.wx.problems;

/**
 * 最小路径和
 */
public class Solution0064 {
    // 动态规划
    public int minPathSum(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] dp = new int[m][n];
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < n; i++) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }

    // 优化到O(n)写法
    public int minPathSum2(int[][] grid) {
        final int m = grid.length;
        final int n = grid[0].length;

        int[] move = new int[n];
        move[0] = grid[0][0];
        for (int i = 1; i < n; i++) {
            move[i] = grid[0][i] + move[i - 1];
        }

        for (int i = 1; i < m; i++) {
            move[0] += grid[i][0];
            for (int j = 1; j < n; j++) {
                move[j] = Math.min(move[j], move[j - 1]) + grid[i][j];
            }
        }

        return move[n - 1];
    }
}
