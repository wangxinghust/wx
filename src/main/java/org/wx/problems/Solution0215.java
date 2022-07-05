package org.wx.problems;

import java.util.PriorityQueue;

/**
 * 215. 数组中的第K个最大元素
 */
public class Solution0215 {
    // 小顶堆
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        for (int i = 0; i < nums.length; i++) {
            if (queue.size() < k) {
                queue.offer(nums[i]);
            } else {
                int val = queue.peek();
                if (val < nums[i]) {
                    queue.poll();
                    queue.offer(nums[i]);
                }
            }
        }
        return queue.peek();
    }

    // 官解一：快排
    // 官解二：堆排，自己实现堆
}
