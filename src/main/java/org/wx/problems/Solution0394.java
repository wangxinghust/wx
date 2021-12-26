package org.wx.problems;

import java.util.Stack;

/**
 * 394. Decode String
 */
public class Solution0394 {
    public String decodeString(String s) {
        Stack<Integer> repeats = new Stack<Integer>();
        char[] chs = s.toCharArray();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < chs.length; i++) {
            if (Character.isDigit(chs[i])) {
                int num = chs[i] - '0';
                while (chs[++i] != '[') {
                    num = num * 10 + chs[i] - '0';
                }
                repeats.push(num);
                repeats.push(sb.length());
            } else if (chs[i] == ']') {
                int index = repeats.pop();
                int num = repeats.pop();
                String str = sb.toString().substring(index);
                for (int j = num; j > 1; j--) {
                    sb.append(str);
                }
            } else {
                sb.append(chs[i]);
            }
        }
        return sb.toString();
    }
}
