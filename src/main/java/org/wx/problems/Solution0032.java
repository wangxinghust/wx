package org.wx.problems;

import java.util.Deque;
import java.util.LinkedList;

/**
 * 32. 最长有效括号
 */
public class Solution0032 {
    //方法二：栈
    public int longestValidParentheses(String s) {
        int maxans = 0;
        Deque<Integer> stack = new LinkedList<Integer>();
        // 初始放入-1比较巧妙，相当于-1处有个无法匹配的')'
        stack.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.isEmpty()) {
                    stack.push(i);
                } else {
                    maxans = Math.max(maxans, i - stack.peek());
                }
            }
        }
        return maxans;
    }
}
