package org.wx.problems;

import java.util.PriorityQueue;

public class Solution0871 {
    // 回溯部分用例超时 109 / 198
    public int minRefuelStops(int target, int startFuel, int[][] stations) {
        int len = stations.length;
        if (len == 0) {
            return target > startFuel ? -1 : 0;
        }
        return minRefuelStops(target, startFuel, stations, 0, 0);
    }

    // newStart用来记录上一次加油位置，但如何用dp表达？
    public int minRefuelStops(int target, int startFuel, int[][] stations, int index, int newStart) {
        if (index == stations.length) {
            return target - newStart > startFuel ? -1 : 0;
        }
        if (stations[index][0] - newStart > startFuel) {
            return -1;
        }
        // 加油
        int res = minRefuelStops(target, startFuel + stations[index][1] - stations[index][0] + newStart, stations, index + 1, stations[index][0]);
        // 不加油
        int res2 = minRefuelStops(target, startFuel, stations, index + 1, newStart);
        if (res == -1) {
            return res2;
        }
        if (res2 == -1) {
            return res + 1;
        }
        return Math.min(res + 1, res2);
    }

    // 方法一：dp，思考的是用dp维护i次加油后的油量，每个加油站依旧是选择加油或不加油，同时判断能否到该加油站。遍历dp得到最小i
    public int minRefuelStops2(int target, int startFuel, int[][] stations) {
        int n = stations.length;
        long[] dp = new long[n + 1];
        dp[0] = startFuel;
        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                if (dp[j] >= stations[i][0]) {
                    dp[j + 1] = Math.max(dp[j + 1], dp[j] + stations[i][1]);
                }
            }
        }
        for (int i = 0; i <= n; i++) {
            if (dp[i] >= target) {
                return i;
            }
        }
        return -1;
    }

    // 方法二：贪心，用队列存加油站，能不加油就不加油，不行就从队列里取油。有点儿回到过去的意思，没油了就在过去的时候取油，从油多的开始取。
    // 比方法一好理解，但队列存储的技巧很特别
    public int minRefuelStops3(int target, int startFuel, int[][] stations) {
        // 大顶堆
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>((a, b) -> b - a);
        int ans = 0, prev = 0, fuel = startFuel;
        int n = stations.length;
        for (int i = 0; i <= n; i++) {
            // 取当前位置
            int curr = i < n ? stations[i][0] : target;
            fuel -= curr - prev;
            // 油量为负时，在过去加油
            while (fuel < 0 && !pq.isEmpty()) {
                fuel += pq.poll();
                ans++;
            }
            if (fuel < 0) {
                return -1;
            }
            if (i < n) {
                pq.offer(stations[i][1]);
                prev = curr;
            }
        }
        return ans;
    }
}
