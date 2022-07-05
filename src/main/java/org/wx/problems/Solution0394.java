package org.wx.problems;

import java.util.Deque;
import java.util.LinkedList;
import java.util.Stack;

/**
 * 394. Decode String
 * 394. 字符串解码
 */
public class Solution0394 {
    // 核心思想就是数字入栈，字母入栈，但是数字入栈时将sb长度入栈即等效于字母入栈
    public String decodeString2(String s) {
        Deque<Integer> repeats = new LinkedList<>();
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
                //sb.append(str.repeat(num));
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
