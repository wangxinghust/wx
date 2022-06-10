package org.wx.sword;

/**
 * 思路拆分判断有符号小数、有符号整数等4个字方法就比较清晰了
 */
public class Solution0200 {
    public boolean isNumber(String s) {
        s = s.trim();
        int index = s.indexOf('e');
        if (index > 0) {
            return isDecimal(s, 0, index) && isInt(s, index + 1, s.length());
        }
        index = s.indexOf('E');
        if (index > 0) {
            return isDecimal(s, 0, index) && isInt(s, index + 1, s.length());
        }
        return isDecimal(s, 0, s.length());
    }

    private boolean isDecimal(String s, int start, int end) {
        if (start >= end) {
            return false;
        }
        if (s.charAt(start) == '+' || s.charAt(start) == '-') {
            return isUnDecimal(s, start + 1, end);
        }
        return isUnDecimal(s, start, end);
    }

    private boolean isUnDecimal(String s, int start, int end) {
        if (start >= end) {
            return false;
        }
        int index = s.indexOf('.');
        if (index == start) {
            return isUnInt(s, start + 1, end);
        }
        if (index == end - 1) {
            return isUnInt(s, start, end - 1);
        }
        if (index > start && index < end) {
            return isUnInt(s, start, index) && isUnInt(s, index + 1, end);
        }
        return isUnInt(s, start, end);
    }

    private boolean isUnInt(String s, int start, int end) {
        if (start >= end) {
            return false;
        }
        for (int i = start; i < end; i++) {
            if (!Character.isDigit(s.charAt(i))) {
                return false;
            }
        }
        return true;
    }

    private boolean isInt(String s, int start, int end) {
        if (start >= end) {
            return false;
        }
        if (s.charAt(start) == '+' || s.charAt(start) == '-') {
            return isUnInt(s, start + 1, end);
        }
        return isUnInt(s, start, end);
    }

    public static void main(String[] args) {
        Solution0200 solution0200 = new Solution0200();
        boolean res = solution0200.isNumber("+.8");
        System.out.println(res);
    }
}
