package org.wx.problems;

import org.junit.jupiter.api.Test;

import java.util.HashMap;
import java.util.Map;

/**
 * @author Wang Xing
 * @date 8/4/21
 */
public class Solution0174Test {
    @Test
    public void testCalculateMinimumHP() {
        Solution0174 solution = new Solution0174();
        int[][] dungeon = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
        for (int i = 0; i < dungeon.length; i++) {
            for (int j = 0; j < dungeon[i].length; j++) {
                System.out.println(dungeon[i][j]);
            }
        }

        int result = solution.calculateMinimumHP(dungeon);
        System.out.println("结果是" + result);
    }

    @Test
    public void testMap() {
        Map<String, Integer> map = new HashMap<>();
        Integer val = map.getOrDefault(null, 0);
        System.out.println(val);
    }
}
