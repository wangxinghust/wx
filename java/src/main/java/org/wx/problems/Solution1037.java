package org.wx.problems;

/**
 * 考察数学基础知识：向量叉乘
 */
public class Solution1037 {
    public boolean isBoomerang(int[][] points) {
        int x = (points[0][1] - points[1][1]) * (points[2][0] - points[1][0]);
        int y = (points[2][1] - points[1][1]) * (points[0][0] - points[1][0]);
        return !(x == y);
    }
}
