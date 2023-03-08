package org.wx.sword;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class Solution0480 {
    public int lengthOfLongestSubstring(String s) {
        int left = 0, right = 0, len = s.length(), maxLen = 0;
        Map<Character, Integer> cntMap = new HashMap<>();
        for (int i = 0; i < len; i++) {
            cntMap.put(s.charAt(i), 0);
        }
        while (left < len && right < len) {
            while (cntMap.get(s.charAt(right)) > 0) {
                cntMap.merge(s.charAt(left++), -1, Integer::sum);
            }
            maxLen = Math.max(maxLen, right - left + 1);
            cntMap.merge(s.charAt(right++), 1, Integer::sum);
        }
        return maxLen;
    }

    /**
     * 用set比map要好，因为本质上出现重复就会删除了，不存在计数
     *
     * @param s
     * @return
     */
    public int lengthOfLongestSubstring2(String s) {
        // 哈希集合，记录每个字符是否出现过
        Set<Character> occ = new HashSet<Character>();
        int n = s.length();
        // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
        int rk = -1, ans = 0;
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                // 左指针向右移动一格，移除一个字符
                occ.remove(s.charAt(i - 1));
            }
            while (rk + 1 < n && !occ.contains(s.charAt(rk + 1))) {
                // 不断地移动右指针
                occ.add(s.charAt(rk + 1));
                ++rk;
            }
            // 第 i 到 rk 个字符是一个极长的无重复字符子串
            ans = Math.max(ans, rk - i + 1);
        }
        return ans;
    }
}
