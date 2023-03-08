package org.wx.problems;

public class Solution0730 {
    /**
     * 依然还是要弄明白转移方程，dp
     *
     * @param s
     * @return
     */
    public int countPalindromicSubsequences2(String s) {
        final int MOD = 1000000007;
        int n = s.length();
        int[][][] dp = new int[4][n][n];
        for (int i = 0; i < n; i++) {
            dp[s.charAt(i) - 'a'][i][i] = 1;
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                for (char c = 'a'; c <= 'd'; c++) {
                    int k = c - 'a';
                    if (s.charAt(i) == c && s.charAt(j) == c) {
                        dp[k][i][j] = (2 + (dp[0][i + 1][j - 1] + dp[1][i + 1][j - 1]) % MOD + (dp[2][i + 1][j - 1] + dp[3][i + 1][j - 1]) % MOD) % MOD;
                    } else if (s.charAt(i) == c) {
                        dp[k][i][j] = dp[k][i][j - 1];
                    } else if (s.charAt(j) == c) {
                        dp[k][i][j] = dp[k][i + 1][j];
                    } else {
                        dp[k][i][j] = dp[k][i + 1][j - 1];
                    }
                }
            }
        }

        int res = 0;
        for (int i = 0; i < 4; i++) {
            res = (res + dp[i][0][n - 1]) % MOD;
        }
        return res;
    }

    /**
     * 思路完全错误
     *
     * @param s
     * @return
     */
    public int countPalindromicSubsequences(String s) {
        int len = s.length();
        char[] chars = s.toCharArray();
        int[][] cnt = new int[len][len];
        int[][] alpha = new int[len][4];
        for (int i = 0; i < len; i++) {
            cnt[i][i] = 1;
            alpha[i][chars[i] - 'a']++;
        }
        for (int j = 1; j < len; j++) {
            for (int i = 0; i < len - j; i++) {
                if (chars[i] == chars[i + j]) {
                    cnt[i][i + j] = cnt[i][i + j - 1] + 1;
                } else {
                    cnt[i][i + j] = cnt[i][i + j - 1];
                }
                if (alpha[i][chars[i + j] - 'a'] == 0) {
                    cnt[i][i + j]++;
                    alpha[i][chars[i + j] - 'a']++;
                }
                if (cnt[i][i + j] > 10e9 + 7) {
                    cnt[i][i + j] %= 10e9 + 7;
                }
            }
        }
        return cnt[0][len - 1];
    }
}
