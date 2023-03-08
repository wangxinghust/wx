package org.wx.problems;

public class Solution0521 {
    public int findLUSlength(String a, String b) {
        int len = -1;
        if (!isSubSequence(a, b)) {
            len = Math.max(len, a.length());
        }
        if (!isSubSequence(b, a)) {
            len = Math.max(len, b.length());
        }
        return len;
    }

    private boolean isSubSequence(String a, String b) {
        if (a.length() > b.length()) {
            return false;
        }
        int i = 0, j = 0;
        while (i < a.length() && j < b.length()) {
            if (a.charAt(i) == b.charAt(j++)) {
                i++;
            }
        }
        return i == a.length();
    }
}
