package org.wx.problems;

import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Solution0719 {
    // 超时或内存超出
    public int smallestDistancePair(int[] nums, int k) {
        PriorityQueue<Integer> queue = new PriorityQueue<Integer>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o2.compareTo(o1);
            }
        });
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                int distance = Math.abs(nums[i] - nums[j]);
                //System.out.println(distance);
                if (queue.isEmpty() || queue.size() < k || distance < queue.peek()) {
                    queue.offer(distance);
                    if (queue.size() > k) {
                        queue.poll();
                    }
                }
            }
        }
        return queue.peek();
    }

    // 暴力方法超时，那就反向思考，暴力是先算distance，再找第k小。反向思路是选distance，看distance是第几个，恰好等于k则为答案。
    // 思路=排序+二分+双指针。双指针可以改为二分，但效率相对低，且代码更复杂
    public int smallestDistancePair2(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length, left = 0, right = nums[n - 1] - nums[0];
        while (left <= right) {
            int mid = (left + right) / 2;
            int cnt = 0;
            for (int i = 0, j = 0; j < n; j++) {
                while (nums[j] - nums[i] > mid) {
                    i++;
                }
                cnt += j - i;
            }
            if (cnt >= k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
