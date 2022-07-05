package org.wx.problems;

/**
 * 198. 打家劫舍
 */
public class Solution0198 {
    // 动态规划，以i结尾偷，能获取的最大金额
    public int rob(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }
        int[] dp = new int[nums.length];
        for (int i = 0; i < dp.length; i++) {
            dp[i] = nums[i] + Math.max(i >= 2 ? dp[i - 2] : 0, i >= 3 ? dp[i - 3] : 0);
        }
        return Math.max(dp[nums.length - 1], dp[nums.length - 2]);
    }

    // 官解动态规划思路不同，选择偷或不偷来解
    public int rob2(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int length = nums.length;
        if (length == 1) {
            return nums[0];
        }
        int[] dp = new int[length];
        dp[0] = nums[0];
        dp[1] = Math.max(nums[0], nums[1]);
        for (int i = 2; i < length; i++) {
            dp[i] = Math.max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[length - 1];
    }
}
