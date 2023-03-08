package org.wx.problems;

/**
 * 240. 搜索二维矩阵 II
 */
public class Solution0240 {
    // 朴素，利用左下角及右上角，官解三同理，且官解三只搜索了一边，可以两边同时搜索
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length;
        int row1 = 0, col1 = n - 1, row2 = m - 1, col2 = 0;
        while (row1 <= row2 && col1 >= col2) {
            if (matrix[row1][col1] == target) {
                return true;
            } else if (matrix[row1][col1] > target) {
                col1--;
            } else {
                row1++;
            }

            if (matrix[row2][col2] == target) {
                return true;
            } else if (matrix[row2][col2] > target) {
                row2--;
            } else {
                col2++;
            }
        }
        return false;
    }
}
