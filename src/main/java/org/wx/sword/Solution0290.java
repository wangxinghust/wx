package org.wx.sword;

import java.util.Arrays;

public class Solution0290 {
    public int[] spiralOrder(int[][] matrix) {
        int rows = matrix.length;
        if (rows == 0) {
            return new int[0];
        }
        int cols = matrix[0].length;
        int[] res = new int[rows * cols];
        int up = 0, down = rows - 1, left = 0, right = cols - 1;
        int index = 0;
        while (up < down && left < right) {
            for (int i = left; i <= right; i++) {
                res[index++] = matrix[up][i];
            }
            up++;
            for (int i = up; i <= down; i++) {
                res[index++] = matrix[i][right];
            }
            right--;
            for (int i = right; i >= left; i--) {
                res[index++] = matrix[down][i];
            }
            down--;

            for (int i = down; i >= up; i--) {
                res[index++] = matrix[i][left];
            }
            left++;

        }
        // 处理好两种特殊情况即可
        if (rows % 2 == 1) {
            for (int i = left; i <= right; i++) {
                res[index++] = matrix[up][i];
            }
            up++;
        }
        if (cols % 2 == 1) {
            for (int i = up; i <= down; i++) {
                res[index++] = matrix[i][right];
            }
            // 此处是为了保持写法统一，多余的
            right--;
        }
        return res;
    }

    public static void main(String[] args) {
        Solution0290 solution0290 = new Solution0290();
        int[][] matrix = new int[][]{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        int[] res = solution0290.spiralOrder(matrix);
        System.out.println(Arrays.toString(res));
    }
}
