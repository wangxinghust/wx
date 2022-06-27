package org.wx.problems;

/**
 * 522. Longest Uncommon Subsequence II
 * 关键处就是要明白加入abc是uncommon subsequence，那就不存在abcd不是uncommon subsequence的情况。因为abcd能从其他str删减得来，那再删掉d即得到abc
 * 因此可以直接从strs数组中找那个最长的字串，而无需枚举出所有subsequence
 */
public class Solution0522 {
    public int findLUSlength(String[] strs) {
        int maxLen = -1;
        for (int i = 0; i < strs.length; i++) {
            boolean isSub = false;
            for (int j = 0; j < strs.length; j++) {
                if (i != j && isSubsequence(strs[i], strs[j])) {
                    isSub = true;
                    break;
                }
            }
            if (!isSub) {
                maxLen = Math.max(maxLen, strs[i].length());
            }
        }
        return maxLen;
    }

    /**
     * 判断s1是否是s2的subsequence
     *
     * @return boolean
     */
    private boolean isSubsequence(String s1, String s2) {
        if (s1.length() > s2.length()) {
            return false;
        }
        int i = 0, j = 0, n1 = s1.length(), n2 = s2.length();
        while (i < n1 && j < n2) {
            if (s1.charAt(i) == s2.charAt(j++)) {
                i++;
            }
        }
        return i == n1;
    }
}
