package org.wx.problems;

/**
 * 115. Distinct Subsequences
 */
public class Solution0115 {
    public static void main(String[] args) {
        Solution0115 solution = new Solution0115();
        int ans = solution.numDistinct("babgbag", "bag");
        System.out.println(ans);
    }

    public int numDistinct(String s, String t) {
        char[] chs = s.toCharArray();
        char[] cht = t.toCharArray();
        int[][] dp = new int[chs.length + 1][cht.length + 1];
        // 初始化 s串生成空串的方法有1种
        for (int i = 0; i < chs.length + 1; i++) {
            dp[i][cht.length] = 1;
        }
        for (int j = cht.length - 1; j >= 0; j--) {
            for (int i = chs.length - 1; i >= 0; i--) {
                if (chs[i] == cht[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }
        return dp[0][0];
    }
}
