package org.wx.problems;

/**
 * @author Wang Xing
 * @date 8/5/21
 */
public class Solution0174 {
    /**
     * 174. Dungeon Game
     * 2021-8-4 23:09:36
     */
    public int calculateMinimumHP(int[][] dungeon) {
        int m = dungeon.length;
        int n = dungeon[0].length;
        int[][] data = new int[m][n];
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) {
                    data[i][j] = -dungeon[i][j];
                } else if (i == m - 1) {
                    data[i][j] = data[i][j + 1] - dungeon[i][j];
                } else if (j == n - 1) {
                    data[i][j] = data[i + 1][j] - dungeon[i][j];
                } else {
                    data[i][j] = Integer.min(i == m - 1 ? 0 : data[i + 1][j], j == n - 1 ? 0 : data[i][j + 1]) - dungeon[i][j];
                }
                data[i][j] = Integer.max(data[i][j], 0);
            }
        }
        return data[0][0] + 1;
    }
}
