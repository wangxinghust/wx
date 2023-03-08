package org.wx.problems;

import java.util.Arrays;

/**
 * 322. 零钱兑换
 */
public class Solution0322 {
    // 动态规划
    public int coinChange(int[] coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, -1);
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.length; j++) {
                if (coins[j] == i) {
                    dp[i] = 1;
                    break;
                }
                if (i - coins[j] > 0 && dp[i - coins[j]] != -1) {
                    if (dp[i] == -1) {
                        dp[i] = dp[i - coins[j]] + 1;
                    } else {
                        dp[i] = Math.min(dp[i], dp[i - coins[j]] + 1);
                    }
                }
            }
            //System.out.println("i="+i+",dp[i]="+dp[i]);
        }
        return dp[amount];
    }

    // 官解二：动态规划，数组填充标记换一下，避免判断-1
    public int coinChange2(int[] coins, int amount) {
        int max = amount + 1;
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, max);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.length; j++) {
                if (coins[j] <= i) {
                    dp[i] = Math.min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
}
