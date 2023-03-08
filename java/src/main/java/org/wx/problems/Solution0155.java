package org.wx.problems;

import java.util.Deque;
import java.util.LinkedList;
import java.util.Stack;

/**
 * 155. 最小栈
 */
public class Solution0155 {
    class MinStack {

        Stack<Integer> stack;
        Stack<Integer> min;

        public MinStack() {
            stack = new Stack<>();
            min = new Stack<>();
        }

        public void push(int val) {
            stack.push(val);
            if (min.size() == 0 || min.size() > 0 && min.peek() > val) {
                min.push(val);
            } else {
                min.push(min.peek());
            }
        }

        public void pop() {
            stack.pop();
            min.pop();
        }

        public int top() {
            return stack.peek();
        }

        public int getMin() {
            return min.peek();
        }
    }

    class MinStack2 {
        Deque<Integer> stack;
        Deque<Integer> min;
        int minN;

        public MinStack2() {
            stack = new LinkedList<>();
            min = new LinkedList<>();
            minN = Integer.MAX_VALUE;
        }

        public void push(int val) {
            stack.push(val);
            minN = Math.min(minN, val);
            min.push(minN);
        }

        public void pop() {
            stack.pop();
            min.pop();
            if (!min.isEmpty()) {
                minN = min.peek();
            } else {
                minN = Integer.MAX_VALUE;
            }
        }

        public int top() {
            return stack.peek();
        }

        public int getMin() {
            return minN;
        }
    }
}
