package org.wx.sword;

import java.util.Stack;

public class Solution0090 {
    class CQueue {
        Stack<Integer> stackTail;
        Stack<Integer> stackDelete;

        public CQueue() {
            stackTail = new Stack<Integer>();
            stackDelete = new Stack<Integer>();
        }

        public void appendTail(int value) {
            stackTail.push(value);
        }

        public int deleteHead() {
            if (stackDelete.empty()) {
                while (!stackTail.empty()) {
                    stackDelete.push(stackTail.pop());
                }
            }
            if (stackDelete.empty()) {
                return -1;
            }
            return stackDelete.pop();
        }
    }

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue obj = new CQueue();
 * obj.appendTail(value);
 * int param_2 = obj.deleteHead();
 */
}
