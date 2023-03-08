package org.wx.problems;

import java.util.LinkedList;
import java.util.Queue;

public class Solution1293 {
    public int shortestPath(int[][] grid, int k) {
        if (k == 0 && grid[0][0] == 1) {
            return -1;
        }

        int rows = grid.length;
        int columns = grid[0].length;
        if (k > rows + columns - 2) {
            return rows + columns - 2;
        }

        final int[][] delta = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int i, size, level;
        int x, y, eliminatedTillNow;
        int[] location;

        // to check if a location (x, y) has been visited after eliminating m number of obstacles
        // if so, then visited[x][y][m] will be true
        // if this part is understood then this problem is very easy
        boolean[][][] visited = new boolean[rows][columns][k + 1];

        Queue<int[]> queue = new LinkedList<int[]>();
        queue.offer(new int[]{0, 0, 0});
        visited[0][0][0] = true;
        level = 0;

        while (!queue.isEmpty()) {
            size = queue.size();
            for (i = 0; i < size; i++) {
                location = queue.poll();
                if (location[0] == rows - 1 && location[1] == columns - 1) {
                    return level;
                }

                eliminatedTillNow = location[2];

                for (int[] direction : delta) {
                    x = location[0] + direction[0];
                    y = location[1] + direction[1];

                    if (x >= 0 && x < rows && y >= 0 && y < columns) {
                        if (grid[x][y] == 1) {
                            if ((eliminatedTillNow < k) && !visited[x][y][eliminatedTillNow + 1]) {
                                // attempt obstacle elimination if possible
                                // i.e. we have eliminated less than k obstacles till this point of time
                                queue.offer(new int[]{x, y, eliminatedTillNow + 1});
                                visited[x][y][eliminatedTillNow + 1] = true;
                            }
                        } else {
                            if (!visited[x][y][eliminatedTillNow]) {
                                queue.offer(new int[]{x, y, eliminatedTillNow});
                                visited[x][y][eliminatedTillNow] = true;
                            }
                        }
                    }
                }
            }

            ++level;
        }

        return -1;
    }
}
