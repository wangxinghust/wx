package org.wx.sword;

public class Solution0420 {
    public int maxSubArray(int[] nums) {
        int sum = 0, maxSum = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            maxSum = Math.max(sum, maxSum);
            sum = sum < 0 ? 0 : sum;
        }
        return maxSum;
    }
}
