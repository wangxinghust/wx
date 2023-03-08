package org.wx.problems;

import java.util.Arrays;

public class Solution0073 {
    public static void main(String[] args) {
        int[][] matrix = {{1, 2, 3, 4}, {5, 0, 7, 8}, {0, 10, 11, 12}, {13, 14, 15, 0}};
        System.out.println(Arrays.deepToString(matrix));
        Solution0073 solution = new Solution0073();
        solution.setZeroes(matrix);
        System.out.println(Arrays.deepToString(matrix));
    }

    /**
     * 73. Set Matrix Zeroes
     */
    public void setZeroes(int[][] matrix) {
        boolean firstCol = false;
        int m = matrix.length;
        int n = matrix[0].length;
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) firstCol = true;
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        // 以下两循环可以合并，若matrix[i][0]或matrix[0][j]为0，即可设置matrix[i][j]=0
        for (int i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 1; j < n; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (matrix[0][0] == 0) {
            for (int j = 1; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        if (firstCol) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
}

