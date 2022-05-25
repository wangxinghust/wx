package org.wx.problems;

import java.util.Stack;

public class Solution0232 {
    class MyQueue {
        Stack<Integer> pushStack;
        Stack<Integer> popStack;

        public MyQueue() {
            pushStack = new Stack();
            popStack = new Stack();
        }

        public void push(int x) {
            pushStack.push(x);
        }

        public int pop() {
            if (popStack.size() == 0) {
                move();
            }
            return popStack.pop();
        }

        public int peek() {
            if (popStack.size() == 0) {
                move();
            }
            return popStack.peek();
        }

        public boolean empty() {
            return pushStack.empty() && popStack.empty();
        }

        private void move() {
            while (!pushStack.empty()) {
                Integer value = pushStack.pop();
                popStack.push(value);
            }
        }
    }
}
