package org.wx.problems;

/**
 * @author Wang Xing
 * @date 8/5/21
 */
public class Solution0188 {
    /**
     * Approach by sireesh
     * <p>
     * Easy to understand explanation for the above solution
     * <p>
     * dp[i][j] = maximum profit from at most i transactions using prices[0..j]
     * <p>
     * A transaction is defined as one buy + sell.
     * <p>
     * Now on day j, we have two options
     * <p>
     * Do nothing (or buy) which doesn't change the acquired profit : dp[i][j] = dp[i][j-1]
     * <p>
     * Sell the stock: In order to sell the stock, you must've bought it on a day t=[0..j-1]. Maximum profit that can be attained is t:0->j-1 max(prices[j]-prices[t]+dp[i-1][t-1]) where prices[j]-prices[t] is the profit from buying on day t and selling on day j. dp[i-1][t-1] is the maximum profit that can be made with at most i-1 transactions with prices prices[0..t-1].
     * <p>
     * Time complexity of this approach is O(n2k).
     * <p>
     * In order to reduce it to O(nk), we must find t:0->j-1 max(prices[j]-prices[t]+dp[i-1][t-1]) this expression in constant time. If you see carefully,
     * <p>
     * t:0->j-1 max(prices[j]-prices[t]+dp[i-1][t-1]) is same as
     * <p>
     * prices[j] + t:0->j-1 max(dp[i-1][t-1]-prices[t])
     * <p>
     * Second part of the above expression maxTemp = t:0->j-1 max(dp[i-1][t-1]-prices[t]) can be included in the dp loop by keeping track of the maximum value till j-1.
     * <p>
     * Base case:
     * <p>
     * dp[0][j] = 0; dp[i][0] = 0
     * <p>
     * DP loop:
     * <p>
     * for i : 1 -> k
     * maxTemp = -prices[0];
     * for j : 1 -> n-1
     * dp[i][j] = max(dp[i][j-1], prices[j]+maxTemp);
     * maxTemp = max(maxTemp, dp[i-1][j-1]-prices[j]);
     * return dp[k][n-1];
     */
    public int maxProfit(int k, int[] prices) {
        int n = prices.length;
        if (n < 1) {
            return 0;
        }
        int[][] dp = new int[k + 1][n];
        for (int i = 1; i < k + 1; i++) {
            int maxTemp = -prices[0];
            for (int j = 1; j < n; j++) {
                dp[i][j] = Math.max(dp[i][j - 1], prices[j] + maxTemp);
                maxTemp = Math.max(maxTemp, dp[i - 1][j - 1] - prices[j]);
            }
        }
        return dp[k][n - 1];
    }
}
