package org.wx.problems;

/**
 * 647. 回文子串
 */
public class Solution0647 {
    public int countSubstrings(String s) {
        int ans = 0;
        // 奇数回文子串
        for (int i = 0; i < s.length(); i++) {
            ans++;
            for (int j = 1; i - j >= 0 && i + j < s.length(); j++) {
                if (s.charAt(i - j) == s.charAt(i + j)) {
                    ans++;
                } else {
                    break;
                }
            }
        }
        // 偶数回文子串
        for (int i = 0; i < s.length() - 1; i++) {
            if (s.charAt(i) == s.charAt(i + 1)) {
                ans++;
                for (int j = 1; i - j >= 0 && i + 1 + j < s.length(); j++) {
                    if (s.charAt(i - j) == s.charAt(i + 1 + j)) {
                        ans++;
                    } else {
                        break;
                    }
                }
            }
        }
        return ans;
    }
}
