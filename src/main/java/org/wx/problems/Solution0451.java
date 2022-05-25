package org.wx.problems;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Solution0451 {
    public String frequencySort(String s) {
        char[] chs = s.toCharArray();
        HashMap<Character, Integer> map = new HashMap<>();
        for (char ch : chs) {
            map.merge(ch, 1, Integer::sum);
        }
        List<Map.Entry<Character, Integer>> list = new ArrayList<>(map.entrySet());
        list.sort((o1, o2) -> o2.getValue().compareTo(o1.getValue()));
        StringBuilder builder = new StringBuilder();
        for (Map.Entry<Character, Integer> entry : list) {
            builder.append(String.valueOf(entry.getKey()).repeat(entry.getValue()));
        }
        return builder.toString();
    }
}
