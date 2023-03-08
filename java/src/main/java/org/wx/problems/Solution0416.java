package org.wx.problems;

/**
 * 416. 分割等和子集
 */
public class Solution0416 {
    // 官解一：动态规划
    // 求数组和，一分为二，转化为背包问题
    public boolean canPartition(int[] nums) {
        int n = nums.length;
        // n<2，则不可能将数组分割成元素和相等的两个子集，因此直接返回 false
        if (n < 2) {
            return false;
        }
        int sum = 0, maxNum = 0;
        for (int num : nums) {
            sum += num;
            maxNum = Math.max(maxNum, num);
        }
        // 如果 sum 是奇数，则不可能将数组分割成元素和相等的两个子集
        if (sum % 2 != 0) {
            return false;
        }
        // 如果 maxNum>target，则除了 maxNum 以外的所有元素之和一定小于 target，因此不可能将数组分割成元素和相等的两个子集，直接返回 false。
        int target = sum / 2;
        if (maxNum > target) {
            return false;
        }
        // 其中 dp[i][j] 表示从数组的 [0,i]下标范围内选取若干个正整数（可以是 0 个），是否存在一种选取方案使得被选取的正整数的和等于 j
        boolean[][] dp = new boolean[n][target + 1];
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for (int i = 1; i < n; i++) {
            int num = nums[i];
            for (int j = 1; j <= target; j++) {
                if (j >= num) {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][target];
    }
}
