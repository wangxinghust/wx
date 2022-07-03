package org.wx.problems;

import java.util.Arrays;
import java.util.Deque;
import java.util.LinkedList;

public class Solution0503 {
    public int[] nextGreaterElements(int[] nums) {
        int n = nums.length;
        int[] ret = new int[n];
        Arrays.fill(ret, -1);
        Deque<Integer> stack = new LinkedList<Integer>();
        // 循环数组则压2遍入栈
        for (int i = 0; i < n * 2 - 1; i++) {
            // 单调不升栈
            while (!stack.isEmpty() && nums[stack.peek()] < nums[i % n]) {
                ret[stack.pop()] = nums[i % n];
            }
            stack.push(i % n);
        }
        return ret;
    }
}
