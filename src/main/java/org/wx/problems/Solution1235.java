package org.wx.problems;

import java.util.Arrays;

/**
 * 1235. Maximum Profit in Job Scheduling
 */
public class Solution1235 {
    public static void main(String[] args) {
        Solution1235 solution = new Solution1235();
        int[] startTime = {4, 2, 4, 8, 2};
        int[] endTime = {5, 5, 5, 10, 8};
        int[] profit = {1, 2, 8, 10, 4};
        int res = solution.jobScheduling(startTime, endTime, profit);
        System.out.println(res);
    }

    /**
     * 排序还是利用java的排序，新增可排序对象
     */
    private class Pair implements Comparable<Pair> {
        int st, et, profit;

        Pair(int st, int et, int profit) {
            this.st = st;
            this.et = et;
            this.profit = profit;
        }

        public int compareTo(Pair o) {
            if (this.st != o.st) {
                return this.st - o.st;
            } else {
                return this.et - o.et;
            }
        }
    }

    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        Pair[] inp = new Pair[startTime.length];

        for (int i = 0; i < startTime.length; i++) {
            inp[i] = new Pair(startTime[i], endTime[i], profit[i]);
        }
        Arrays.sort(inp);

        int n = startTime.length;
        int[] dp = new int[n + 1];
        // dp初始化，最后一个任务必定执行
        dp[n - 1] = inp[n - 1].profit;
        for (int i = n - 2; i >= 0; i--) {
            dp[i] = Math.max(dp[upperBound(inp, inp[i].et, i, n)] + inp[i].profit, dp[i + 1]);
        }
        return dp[0];
    }

    private void sort(int[] startTime, int[] endTime, int[] profit) {
        for (int i = 0; i < startTime.length; i++) {
            for (int j = i + 1; j < startTime.length; j++) {
                if (startTime[i] > startTime[j]) {
                    swap(startTime, i, j);
                    swap(endTime, i, j);
                    swap(profit, i, j);
                }
                if (startTime[i] == startTime[j] && endTime[i] > endTime[j]) {
                    swap(startTime, i, j);
                    swap(endTime, i, j);
                    swap(profit, i, j);
                }
            }
        }
    }

    private void swap(int[] a, int i, int j) {
        int swap = a[i];
        a[i] = a[j];
        a[j] = swap;
    }

    /**
     * 查找第一个大于等于目标值的索引
     * 优化为只查指定区域的
     */
    private int upperBound(Pair[] a, int x, int l, int r) {
        while (l < r) {
            int m = (l + r) >>> 1;
            if (a[m].st < x) l = m + 1;
            else r = m;
        }
        return l;
    }
}
