package org.wx.sword;

import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;

/**
 * 单调减队列
 */
public class Solution0592 {
    class MaxQueue {

        Queue<Integer> q;
        Deque<Integer> d;

        public MaxQueue() {
            q = new LinkedList<Integer>();
            d = new LinkedList<Integer>();
        }

        public int max_value() {
            if (d.isEmpty()) {
                return -1;
            }
            return d.peekFirst();
        }

        public void push_back(int value) {
            while (!d.isEmpty() && d.peekLast() < value) {
                d.pollLast();
            }
            d.offerLast(value);
            q.offer(value);
//            print(d);
        }

        public int pop_front() {
            if (q.isEmpty()) {
                return -1;
            }
            int ans = q.poll();
            if (ans == d.peekFirst()) {
                d.pollFirst();
            }
            return ans;
        }

        private void print(Deque<Integer> d) {
            int size = d.size();
            while (size > 0) {
                int value = d.pollFirst();
                System.out.print(value);
                System.out.print(",");
                d.offerLast(value);
                size--;
            }
            System.out.println();
        }
    }

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue obj = new MaxQueue();
 * int param_1 = obj.max_value();
 * obj.push_back(value);
 * int param_3 = obj.pop_front();
 */
}
