package org.wx.problems;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Solution0022 {
    // 错误解答，处理不了"(())(())"这类情况
    public List<String> generateParenthesis(int n) {
        Set<String> parenthesis = new HashSet<String>();
        backstrack(n, 0, parenthesis, "");
        return new ArrayList<>(parenthesis);
    }

    private void backstrack(int n, int index, Set<String> parenthesis, String str) {
        if (n == index) {
            parenthesis.add(str);
        } else {
            backstrack(n, index + 1, parenthesis, "()" + str);
            backstrack(n, index + 1, parenthesis, str + "()");
            backstrack(n, index + 1, parenthesis, "(" + str + ")");
        }
    }

    // 回溯法，但是要分左括号和右括号
    public List<String> generateParenthesis2(int n) {
        List<String> parenthesis = new ArrayList<String>();
        backtrack(parenthesis, new StringBuilder(), 0, 0, n);
        return parenthesis;
    }

    private void backtrack(List<String> ans, StringBuilder sb, int open, int close, int n) {
        if (sb.length() == n * 2) {
            ans.add(sb.toString());
        }
        if (open < n) {
            sb.append('(');
            backtrack(ans, sb, open + 1, close, n);
            sb.deleteCharAt(sb.length() - 1);
        }
        if (close < open) {
            sb.append(')');
            backtrack(ans, sb, open, close + 1, n);
            sb.deleteCharAt(sb.length() - 1);
        }
    }

    public static void main(String[] args) {
        List<String> l1 = List.of("()()()()", "(()())()", "(()(()))", "()()(())", "(())()()", "(((())))", "()((()))", "()(())()", "()(()())", "(()()())", "((()()))", "((()))()", "((())())");
        List<String> l2 = new ArrayList<>(List.of("(((())))", "((()()))", "((())())", "((()))()", "(()(()))", "(()()())", "(()())()", "(())(())", "(())()()", "()((()))", "()(()())", "()(())()", "()()(())", "()()()()"));
        l2.removeAll(l1);
        System.out.println(l2);
    }
}
