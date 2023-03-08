package org.wx.problems;

/**
 * 1277. 统计全为 1 的正方形子矩阵
 */
public class Solution1227 {
    // 官解一：动态规划
    // 公式推导： 固定右下角可知其他仨位置 min(f[i][j−1],f[i−1][j],f[i−1][j−1])≥f[i][j]−1
    // & 假设仨位置最小构成，可推 f[i][j]≥min(f[i][j−1],f[i−1][j],f[i−1][j−1])+1
    // =》 f[i][j]=min(f[i][j−1],f[i−1][j],f[i−1][j−1])+1
    public int countSquares(int[][] matrix) {
        int[][] dp = new int[matrix.length][matrix[0].length];
        int ans = 0;
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = matrix[i][j];
                } else if (matrix[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = Math.min(Math.min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }
}
