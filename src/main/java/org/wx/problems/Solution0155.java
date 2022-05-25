package org.wx.problems;

import java.util.Stack;

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
}
