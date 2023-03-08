package org.wx.problems;

public class Solution0258 {
    public int addDigits(int num) {
        if (num == 0) {
            return 0;
        }
        int value = num % 9;
        return value == 0 ? 9 : value;
    }

    public int addDigits2(int num) {
        return num == 0 ? 0 : 1 + (num - 1) % 9;
    }
}
