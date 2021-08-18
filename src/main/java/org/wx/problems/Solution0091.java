package org.wx.problems;

public class Solution0091 {
    public static void main(String[] args) {
        Solution0091 solution = new Solution0091();
        int n = solution.numDecodings("27");
        System.out.println(n);
    }

    public int numDecodings(String s) {
        char[] chars = s.toCharArray();
        int n = chars.length;
        int[] dp = new int[chars.length + 2];
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (chars[i] == '0') {
                dp[i] = 0;
            } else if (chars[i] == '1') {
                dp[i] = dp[i + 1] + dp[i + 2];
            } else if (chars[i] == '2') {
                if (i == n - 1) {
                    dp[i] = 1;
                } else {
                    if (chars[i + 1] <= '6') {
                        dp[i] = dp[i + 1] + dp[i + 2];
                    } else {
                        dp[i] = dp[i + 1];
                    }
                }
            } else {
                dp[i] = dp[i + 1];
            }
        }
        return dp[0];
    }
}
