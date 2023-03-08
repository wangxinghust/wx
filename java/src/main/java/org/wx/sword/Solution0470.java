package org.wx.sword;

public class Solution0470 {
    public int maxValue(int[][] grid) {
        int rows = grid.length, cols = grid[0].length;
        int[][] dp = new int[rows + 1][cols + 1];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dp[i + 1][j + 1] = Math.max(dp[i][j + 1], dp[i + 1][j]) + grid[i][j];
            }
        }
        return dp[rows][cols];
    }
}
