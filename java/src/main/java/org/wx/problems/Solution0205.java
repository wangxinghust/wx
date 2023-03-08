package org.wx.problems;

import java.util.HashMap;

/**
 * @author Wang Xing
 * @date 8/5/21
 */
public class Solution0205 {
    public static void main(String[] args) {
        Solution0205 so = new Solution0205();
        so.isIsomorphic("egg", "add");
    }

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
