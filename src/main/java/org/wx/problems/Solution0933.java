package org.wx.problems;

import java.util.ArrayDeque;
import java.util.Queue;

public class Solution0933 {
    class RecentCounter {
        private Queue<Integer> q;

        public RecentCounter() {
            q = new ArrayDeque<Integer>();
        }

        public int ping(int t) {
            q.offer(t);
            while (q.peek() < t - 3000) {
                q.poll();
            }
            return q.size();
        }
    }

    class RecentCounter2 {
        int left;
        int right;
        int[] times;

        public RecentCounter2() {
            left = 0;
            right = 0;
            times = new int[10005];
        }

        public int ping(int t) {
            times[right++] = t;
            while (times[left] < t - 3000) {
                left++;
            }
            return right - left;
        }
    }
}
