package org.wx.problems;

public class Solution0048 {
    // 难点在公式推导
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        int mid = (n - 1) / 2;
        for (int i = 0; i <= mid; i++) {
            for (int j = i; j < n - 1 - i; j++) {
                int row = j, col = (n - i - 1) % n;
                int last = matrix[i][j];
                for (int k = 0; k < 4; k++) {
                    int tmp = last;
                    last = matrix[row][col];
                    matrix[row][col] = tmp;
                    tmp = row;
                    row = col;
                    col = (n - tmp - 1) % n;
                }
            }
        }
    }

    // 官解1：思路一样
    public void rotate2(int[][] matrix) {
        int n = matrix.length;
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < (n + 1) / 2; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }
    }

    // 官解2：利用翻转替代，90°旋转=水平翻+主对角线翻
    public void rotate3(int[][] matrix) {
        int n = matrix.length;
        // 水平翻转
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - i - 1][j];
                matrix[n - i - 1][j] = temp;
            }
        }
        // 主对角线翻转
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
}