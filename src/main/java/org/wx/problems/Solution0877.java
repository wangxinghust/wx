package org.wx.problems;

import java.util.Arrays;

/**
 * @author Wang Xing
 * @date 8/5/21
 */
public class Solution0877 {
    public static void main(String[] args) {
        int[] piles = {29, 2, 43, 20, 10, 15, 21, 4, 17, 49, 7, 24, 6, 27, 16, 23, 5, 18, 18, 23, 30, 28, 10, 28, 32, 33, 29, 32, 30, 36, 43, 39, 33, 7, 30, 42, 35, 50, 10, 2, 21, 35, 27, 20, 27, 33, 24, 47, 43, 50};
        Solution0877 solution = new Solution0877();
        System.out.println(solution.stoneGame(piles));
    }

    /**
     * 877. Stone Game
     * 递归超时
     */
    public boolean stoneGame(int[] piles) {
        if (piles.length == 2) {
            return true;
        }
        int i = 0, j = piles.length - 1;
        int left = 0, right = 0;
        return recursiveSum(piles, i + 1, j, left + piles[i], right) || recursiveSum(piles, i, j - 1, left + piles[j], right);
    }

    private boolean recursiveSum(int[] piles, int i, int j, int left, int right) {
        System.out.println("i=" + i + ",j=" + j);
        if (i + 1 >= j) {
            return left + Math.max(piles[i], piles[j]) > right + Math.min(piles[i], piles[j]);
        }
        if ((j - i) % 2 == 0) {
            return recursiveSum(piles, i + 1, j, left + piles[i], right) || recursiveSum(piles, i, j - 1, left + piles[j], right);
        } else {
            return recursiveSum(piles, i + 1, j, left, right + piles[i]) && recursiveSum(piles, i, j - 1, left, right + piles[j]);
        }
    }

    /**
     * Approach by lee215
     * <p>
     * Approach 1: Just return true
     * Alex is first to pick pile.
     * piles.length is even, and this lead to an interesting fact:
     * Alex can always pick odd piles or always pick even piles!
     * <p>
     * For example,
     * If Alex wants to pick even indexed piles piles[0], piles[2], ....., piles[n-2],
     * he picks first piles[0], then Lee can pick either piles[1] or piles[n - 1].
     * Every turn, Alex can always pick even indexed piles and Lee can only pick odd indexed piles.
     * <p>
     * In the description, we know that sum(piles) is odd.
     * If sum(piles[even]) > sum(piles[odd]), Alex just picks all evens and wins.
     * If sum(piles[even]) < sum(piles[odd]), Alex just picks all odds and wins.
     * <p>
     * So, Alex always defeats Lee in this game.
     * <p>
     * Approach 2: 2D DP
     * It's tricky when we have even number of piles of stones. You may not have this condition in an interview.
     * <p>
     * Follow-up:
     * <p>
     * What if piles.length can be odd?
     * What if we want to know exactly the diffenerce of score?
     * Then we need to solve it with DP.
     * <p>
     * dp[i][j] means the biggest number of stones you can get more than opponent picking piles in piles[i] ~ piles[j].
     * You can first pick piles[i] or piles[j].
     * <p>
     * If you pick piles[i], your result will be piles[i] - dp[i + 1][j]
     * If you pick piles[j], your result will be piles[j] - dp[i][j - 1]
     * So we get:
     * dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1])
     * We start from smaller subarray and then we use that to calculate bigger subarray.
     * <p>
     * Note that take evens or take odds, it's just an easy strategy to win when the number of stones is even.
     * It's not the best solution!
     * I didn't find a tricky solution when the number of stones is odd (maybe there is).
     */
    public boolean stoneGame2(int[] piles) {
        int n = piles.length;
        int[][] dp = new int[n][n];
        for (int i = 0; i < n; i++) dp[i][i] = piles[i];
        for (int d = 1; d < n; d++)
            for (int i = 0; i < n - d; i++)
                dp[i][i + d] = Math.max(piles[i] - dp[i + 1][i + d], piles[i + d] - dp[i][i + d - 1]);
        return dp[0][n - 1] > 0;
    }

    /**
     * Approach 3: 1D DP
     * Follow up: Use only O(N) space?
     * <p>
     * Simplify to 1D DP.
     */
    public boolean stoneGame3(int[] piles) {
        int n = piles.length;
        int[] dp = Arrays.copyOf(piles, n);
        for (int d = 1; d < n; d++) {
            for (int i = 0; i < n - d; i++) {
                dp[i] = Math.max(piles[i] - dp[i + 1], piles[i + d] - dp[i]);
            }
        }
        return dp[0] > 0;
    }
}
