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
     * 优化想法是类似mysql普通索引，对startTime字段排序，根据主键id也就是数组下标查找endTime和profit值，这样就可以变成两个数组的排序，手写快排实现
     */
    private class Pair implements Comparable<Pair> {
        int st, et, profit;

        Pair(int st, int et, int profit) {
            this.st = st;
            this.et = et;
            this.profit = profit;
        }

        @Override
        public int compareTo(Pair o) {
            if (this.st != o.st) {
                return this.st - o.st;
            } else {
                return this.et - o.et;
            }
        }
    }

    /**
     * Runtime: 21 ms
     * Memory Usage: 71 MB
     * 将Pair改为static对象后，内用占用减少
     * Runtime: 13 ms, faster than 91.88% of Java online submissions for Maximum Profit in Job Scheduling.
     * Memory Usage: 47.2 MB, less than 90.45% of Java online submissions for Maximum Profit in Job Scheduling.
     */
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

    /**
     * 方案2 手写快排实现startTime及下标排序
     * 但手写快排效率远不如java优化后的归并排序，内存消耗是少了不少
     * Runtime: 382 ms
     * Memory Usage: 49 MB
     */
    public int jobScheduling2(int[] startTime, int[] endTime, int[] profit) {
        int[] index = new int[startTime.length];
        for (int i = 0; i < index.length; i++) {
            index[i] = i;
        }
        quickSort(startTime, index, 0, startTime.length - 1);
        int[] dp = new int[startTime.length + 1];
        dp[startTime.length - 1] = profit[index[startTime.length - 1]];
        for (int i = startTime.length - 2; i >= 0; i--) {
            dp[i] = Math.max(dp[i + 1], profit[index[i]] + dp[upperBound(startTime, endTime[index[i]], i, startTime.length)]);
        }
        return dp[0];
    }

    private void quickSort(int[] startTime, int[] index, int low, int high) {
        int p, i, j;
        if (low >= high) {
            return;
        }
        // p为基准数，这里取基准数为待排数组的第一个
        p = startTime[low];

        i = low;
        j = high;
        while (i < j) {
            while (startTime[j] >= p && i < j) {
                j--;
            }
            while (startTime[i] <= p && i < j) {
                i++;
            }
            int temp = startTime[i];
            startTime[i] = startTime[j];
            startTime[j] = temp;
            temp = index[i];
            index[i] = index[j];
            index[j] = temp;
        }
        startTime[low] = startTime[i];
        startTime[i] = p;
        int t = index[low];
        index[low] = index[i];
        index[i] = t;
        quickSort(startTime, index, low, i - 1);
        quickSort(startTime, index, i + 1, high);
    }

    private int upperBound(int[] startTime, int value, int l, int r) {
        while (l < r) {
            int m = (l + r) >>> 1;
            if (startTime[m] < value) l = m + 1;
            else r = m;
        }
        return l;
    }
}
