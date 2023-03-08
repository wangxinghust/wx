package org.wx.problems;

import java.util.ArrayList;
import java.util.List;

/**
 * 54. Spiral Matrix
 */
public class Solution0054 {
    public static void main(String[] args) {
        Solution0054 solution = new Solution0054();
        int[][] matrix = new int[][]{{2, 5, 8}, {4, 0, -1}};
        List<Integer> ans = solution.spiralOrder(matrix);
        System.out.println(ans);
    }

    public List<Integer> spiralOrder(int[][] matrix) {
        int up = 0, down = matrix.length - 1, left = 0, right = matrix[0].length - 1;
        List<Integer> ans = new ArrayList<>();
        while (up <= down && left <= right) {
            for (int i = left; i <= right; i++) {
                ans.add(matrix[up][i]);
            }
            up++;

            for (int i = up; i <= down; i++) {
                ans.add(matrix[i][right]);
            }
            right--;

            if (up <= down) {
                for (int i = right; i >= left; i--) {
                    ans.add(matrix[down][i]);
                }
                down--;
            }
            if (left <= right) {
                for (int i = down; i >= up; i--) {
                    ans.add(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
}
