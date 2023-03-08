package org.wx.problems;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

/**
 * 330. Patching Array
 */
public class Solution0330 {
    public static void main(String[] args) {
        Solution0330 solution = new Solution0330();
        int res = solution.minPatches3(new int[]{1, 2, 31, 33}, 2147483647);
        System.out.println(res);
    }

    /**
     * 优化方案是从后往前遍历sum数组，避免使用temp数组
     * 存在n=2^31 - 1的情况，因此不能用len=n+1的方案
     * 而且申请这么大的数组也不靠谱
     */
    public int minPatches(int[] nums, int n) {
        int len = n + 1;
        boolean[] sum = new boolean[len];
        sum[0] = true;
        boolean[] temp = new boolean[len];
        for (int i = 0; i < nums.length; i++) {
            System.arraycopy(sum, 0, temp, 0, len);
            for (int j = 0; j < len - nums[i]; j++) {
                if (sum[j]) {
                    temp[j + nums[i]] = true;
                }
            }
            System.arraycopy(temp, 0, sum, 0, len);
        }
        int cnt = 0;
        for (int i = 1; i < len; i++) {
            if (!sum[i]) {
                ++cnt;
                System.arraycopy(sum, 0, temp, 0, len);
                for (int j = 0; j < len - i; j++) {
                    if (sum[j]) {
                        temp[j + i] = true;
                    }
                }
                System.arraycopy(temp, 0, sum, 0, len);
            }
        }
        return cnt;
    }

    /**
     * Solution 1 by DBabichev
     * merge intervals
     * 仍然是 Time Limit Exceeded
     */
    public int minPatches2(int[] nums, int n) {
        int[][] ints = {{0, 0}};
        int patches = 0;
        for (int num : nums) {
            ints = intsAdd(ints, num);
            ints = merge(ints);
        }
        while (ints[0][1] < n) {
            ints = intsAdd(ints, ints[0][1] + 1);
            ints = merge(ints);
            patches++;
        }
        return patches;
    }

    /**
     * ints数组每个数字均+add
     */
    private int[][] intsAdd(int[][] ints, int add) {
        int[][] temp = new int[2 * ints.length][2];
        System.arraycopy(ints, 0, temp, 0, ints.length);
        for (int i = 0; i < ints.length; i++) {
            for (int j = 0; j < 2; j++) {
                temp[i + ints.length][j] = ints[i][j] + add;
            }
        }
        return temp;
    }

    private int[][] merge(int[][] intervals) {
        if (intervals.length == 0) {
            return new int[0][2];
        }
        Arrays.sort(intervals, new Comparator<int[]>() {
            public int compare(int[] interval1, int[] interval2) {
                return interval1[0] - interval2[0];
            }
        });
        List<int[]> merged = new ArrayList<int[]>();
        for (int i = 0; i < intervals.length; ++i) {
            int L = intervals[i][0], R = intervals[i][1];
            // 与56题差别在于整数区间合并，需要+1
            if (merged.size() == 0 || merged.get(merged.size() - 1)[1] + 1 < L) {
                merged.add(new int[]{L, R});
            } else {
                merged.get(merged.size() - 1)[1] = Math.max(merged.get(merged.size() - 1)[1], R);
            }
        }
        return merged.toArray(new int[merged.size()][]);
    }

    /**
     * Solution 2 by DBabichev
     * greedy
     * 重点依旧在区间，以及贪心算法的证明
     */
    public int minPatches3(int[] nums, int n) {
        long reach = 0;
        int patches = 0, idx = 0;
        while (reach < n) {
            if (idx < nums.length && reach + 1 >= nums[idx]) {
                reach += nums[idx++];
            } else {
                patches++;
                reach += reach + 1;
            }
        }
        return patches;
    }
}
