package org.wx.problems;

import java.util.Arrays;

/**
 * 300. 最长递增子序列
 */
public class Solution0300 {
    public int lengthOfLIS(int[] nums) {
        int[] dp = new int[nums.length];
        Arrays.fill(dp, 1);
        for (int i = 1; i < nums.length; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = Math.max(dp[i], 1 + dp[j]);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < dp.length; i++) {
            //System.out.println(dp[i]);
            ans = Math.max(ans, dp[i]);
        }
        return ans;
    }
}
