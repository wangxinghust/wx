package org.wx.problems;

import java.util.Comparator;
import java.util.PriorityQueue;

/**
 * 239. 滑动窗口最大值
 */
public class Solution0239 {
    public int[] maxSlidingWindow2(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((k1, k2) -> {
            return nums[k2] - nums[k1];
        });
        for (int i = 0; i < k; i++) {
            pq.offer(i);
        }
        int ans[] = new int[nums.length - k + 1];
        ans[0] = nums[pq.peek()];
        for (int i = 1; i < nums.length - k + 1; i++) {
            pq.offer(i + k - 1);
            while (pq.peek() < i) {
                pq.poll();
            }
            ans[i] = nums[pq.peek()];
        }
        return ans;
    }

    //方法一：优先队列
    // 优先队列里放nums-index，取大根堆的peek值时判断一下是否还在窗口内即可
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>(new Comparator<int[]>() {
            public int compare(int[] pair1, int[] pair2) {
                // pair2[1]的排序不重要，不影响结果，也可以考虑只存下标
                return pair1[0] != pair2[0] ? pair2[0] - pair1[0] : pair2[1] - pair1[1];
            }
        });
        for (int i = 0; i < k; ++i) {
            pq.offer(new int[]{nums[i], i});
        }
        int[] ans = new int[n - k + 1];
        ans[0] = pq.peek()[0];
        for (int i = k; i < n; ++i) {
            pq.offer(new int[]{nums[i], i});
            while (pq.peek()[1] <= i - k) {
                pq.poll();
            }
            ans[i - k + 1] = pq.peek()[0];
        }
        return ans;
    }

    //方法二：单调队列
    //方法三：分块 + 预处理
}
