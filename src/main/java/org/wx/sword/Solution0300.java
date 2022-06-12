package org.wx.sword;

import java.util.Stack;

public class Solution0300 {
    class MinStack {
        Stack<Integer> valStack;
        Stack<Integer> minValStack;
        int minVal;

        /**
         * initialize your data structure here.
         */
        public MinStack() {
            valStack = new Stack<Integer>();
            minValStack = new Stack<Integer>();
            minVal = Integer.MAX_VALUE;
        }

        public void push(int x) {
            valStack.push(x);
            minVal = Math.min(minVal, x);
            minValStack.push(minVal);
            //System.out.print(x+" "+minVal+"|");
        }

        public void pop() {
            valStack.pop();
            minValStack.pop();
            if (minValStack.empty()) {
                minVal = Integer.MAX_VALUE;
            } else {
                minVal = minValStack.peek();
            }
        }

        public int top() {
            return valStack.peek();
        }

        public int min() {
            return minVal;
        }
    }

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.min();
 */
}
