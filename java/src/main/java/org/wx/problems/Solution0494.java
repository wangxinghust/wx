package org.wx.problems;

/**
 * 494. 目标和
 */
public class Solution0494 {
    // 回溯
    public int findTargetSumWays(int[] nums, int target) {
        return backtrack(nums, 0, target, 0);
    }

    private int backtrack(int[] nums, int idx, int target, int sum) {
        if (idx == nums.length) {
            return target == sum ? 1 : 0;
        }
        return backtrack(nums, idx + 1, target, sum - nums[idx]) + backtrack(nums, idx + 1, target, sum + nums[idx]);
    }

    // 方法二：动态规划，实质就是转换为背包问题
    // dp[i][j] 表示在数组 nums 的前 i 个数中选取元素，使得这些元素之和等于 j 的方案数
    public int findTargetSumWays2(int[] nums, int target) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        int diff = sum - target;
        if (diff < 0 || diff % 2 != 0) {
            return 0;
        }
        int n = nums.length, neg = diff / 2;
        int[][] dp = new int[n + 1][neg + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            int num = nums[i - 1];
            for (int j = 0; j <= neg; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= num) {
                    dp[i][j] += dp[i - 1][j - num];
                }
            }
        }
        return dp[n][neg];
    }
}
