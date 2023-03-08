package org.wx.problems;

import java.util.HashMap;
import java.util.Map;

/**
 * 565. Array Nesting
 * 主要是证明
 * 数据是单向循环的，nums[nums[k]]是唯一的，形成嵌套即指向成为圆圈。
 * 倒序遍历时，假如有圆圈，则全部遍历，并得到圈长度。溢出则五圈，长度为0
 * <p>
 * 因为数字是唯一的，因此圆圈都是独立的，不存在一条线指向圆圈的情况，更不存在圆圈中的一点偏移出一条线
 */
public class Solution0565 {
    public static void main(String[] args) {
        int[] nums = {0, 1, 2};
        Solution0565 solution = new Solution0565();
        int res = solution.arrayNesting(nums);
        System.out.println(res);
    }

    // 优化思路是不用hashMap，用等长Map存value->index的映射关系，超出长度的value意义不大，无需存储，映射数组初始化为-1用于标记越界
    public int arrayNesting(int[] nums) {
        Map<Integer, Integer> indexMap = new HashMap<>(nums.length);
        for (int i = 0; i < nums.length; i++) {
            indexMap.put(nums[i], i);
        }
        boolean[] isVisit = new boolean[nums.length];
        int len = 0;
        for (int i = 0; i < isVisit.length; i++) {
            if (!isVisit[i]) {
                len = Math.max(len, nestLen(isVisit, indexMap, i, nums));
            }
        }
        return len;
    }

    private int nestLen(boolean[] isVisit, Map<Integer, Integer> indexMap, int index, int[] nums) {
        int num = nums[index];
        int len = 0;
        boolean isCircle = false;
        while (!isVisit[index]) {
            isVisit[index] = true;
            len++;
            index = indexMap.get(index);
            if (index < 0 || index >= nums.length) {
                break;
            }
            if (num == nums[index]) {
                isCircle = true;
                break;
            }
        }
        return isCircle ? len : 0;
    }

    /**
     * Approach 2
     * 标记数组，正向遍历
     * 因为0 <= nums[i] < nums.length，无需考虑越界
     */
    public int arrayNesting2(int[] nums) {
        boolean[] visited = new boolean[nums.length];
        int res = 0;
        for (int i = 0; i < nums.length; i++) {
            if (!visited[i]) {
                int start = nums[i], count = 0;
                do {
                    start = nums[start];
                    count++;
                    visited[start] = true;
                }
                while (start != nums[i]);
                res = Math.max(res, count);
            }
        }
        return res;
    }

    /**
     * 直接利用原数组做标记
     */
    public int arrayNesting3(int[] nums) {
        int res = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != Integer.MAX_VALUE) {
                int start = nums[i], count = 0;
                while (nums[start] != Integer.MAX_VALUE) {
                    int temp = start;
                    start = nums[start];
                    count++;
                    nums[temp] = Integer.MAX_VALUE;
                }
                res = Math.max(res, count);
            }
        }
        return res;
    }
}
