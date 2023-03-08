package org.wx.sword;

public class Solution0460 {
    public int translateNum(int num) {
        int pre = 0, cur = 1, next = 0;
        String str = String.valueOf(num);
        for (int i = 0; i < str.length(); i++) {
            if (i > 0 && ((str.charAt(i - 1) == '1') || (str.charAt(i - 1) == '2' && str.charAt(i) <= '5'))) {
                next = pre + cur;
            } else {
                next = cur;
            }
            pre = cur;
            cur = next;
        }
        return next;
    }
}
