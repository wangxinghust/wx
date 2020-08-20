package com.wx.leetcode205;

import java.util.HashMap;

/**
 * @author Wang Xing
 * @date 8/20/20
 */
public class IsomorphicStrings {
    public static void main(String[] args) {
        Solution so = new Solution();
        so.isIsomorphic("egg", "add");
    }
}

class Solution {
    public boolean isIsomorphic(String s, String t) {
        HashMap<Character, Character> map = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char a = s.charAt(i);
            char b = t.charAt(i);
            if (map.containsKey(a)) {
                if (!map.get(a).equals(b))
                    return false;
            } else {
                if (!map.containsValue(b))
                    map.put(a, b);
                else return false;
            }
        }
        return true;
    }
}
