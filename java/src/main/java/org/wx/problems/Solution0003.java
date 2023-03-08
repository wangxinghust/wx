package org.wx.problems;

public class Solution0003 {
    // 最长子串（注意是子串不是子序列）可以用滑动窗口解，用set还是数组都行，用途一样
    public int lengthOfLongestSubstring(String s) {
        if (s.length() == 0) {
            return 0;
        }
        int left = 0, right = 1, sub = 1;
        boolean[] ch = new boolean[256];
        ch[s.charAt(left)] = true;
        while (left < s.length() && right < s.length()) {
            while (right < s.length() && ch[s.charAt(right)] == false) {
                ch[s.charAt(right++)] = true;
            }
            sub = Math.max(right - left, sub);
            while (left < s.length() && right < s.length() && ch[s.charAt(right)] == true) {
                ch[s.charAt(left++)] = false;
            }
        }
        return sub;
    }
}
