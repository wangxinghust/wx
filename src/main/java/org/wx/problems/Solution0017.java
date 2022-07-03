package org.wx.problems;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Solution0017 {
    // 回溯法
    public List<String> letterCombinations(String digits) {
        List<String> combinations = new ArrayList<>();
        if (digits.length() == 0) {
            return combinations;
        }
        Map<Character, String> phoneMap = new HashMap<>();
        phoneMap.put('2', "abc");
        phoneMap.put('3', "def");
        phoneMap.put('4', "ghi");
        phoneMap.put('5', "jkl");
        phoneMap.put('6', "mno");
        phoneMap.put('7', "pqrs");
        phoneMap.put('8', "tuv");
        phoneMap.put('9', "wxyz");
        backtrack(combinations, phoneMap, digits, 0, new StringBuilder());
        return combinations;
    }

    private void backtrack(List<String> combinations, Map<Character, String> phoneMap, String digits, int index, StringBuilder sb) {
        if (index == digits.length()) {
            combinations.add(sb.toString());
            return;
        }
        String str = phoneMap.get(digits.charAt(index));

        for (int i = 0; i < str.length(); i++) {
            sb.append(str.charAt(i));
            backtrack(combinations, phoneMap, digits, index + 1, sb);
            sb.deleteCharAt(index);
        }
    }
}
