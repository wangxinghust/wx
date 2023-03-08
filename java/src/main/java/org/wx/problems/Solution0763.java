package org.wx.problems;

import java.util.ArrayList;
import java.util.List;

public class Solution0763 {
    public List<Integer> partitionLabels(String s) {
        int[] letters = new int[26];
        for (int i = 0; i < s.length(); i++) {
            letters[s.charAt(i) - 'a'] = i;
        }
        List<Integer> res = new ArrayList<>();
        int began = 0, index = 0, end = letters[s.charAt(began) - 'a'];
        while (index < s.length() && index <= end) {
            if (index == end) {
                res.add(end - began + 1);
                began = end + 1;
                if (began < s.length()) {
                    end = letters[s.charAt(began) - 'a'];
                }
            } else {
                end = Math.max(end, letters[s.charAt(index) - 'a']);
            }
            index++;
        }
        return res;
    }

    public List<Integer> partitionLabels2(String s) {
        int[] last = new int[26];
        for (int i = 0; i < s.length(); ++i)
            last[s.charAt(i) - 'a'] = i;

        int j = 0, anchor = 0;
        List<Integer> ans = new ArrayList();
        for (int i = 0; i < s.length(); ++i) {
            j = Math.max(j, last[s.charAt(i) - 'a']);
            if (i == j) {
                ans.add(i - anchor + 1);
                anchor = i + 1;
            }
        }
        return ans;
    }
}
