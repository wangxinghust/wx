package org.wx.problems;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

/**
 * 76. 最小覆盖子串
 */
public class Solution0076 {
    // 思路就是尽量减少check
    public String minWindow2(String s, String t) {
        Map<Character, Integer> tCnt = new HashMap<>();
        Map<Character, Integer> windowCnt = new HashMap<>();
        for (int i = 0; i < t.length(); i++) {
            tCnt.put(t.charAt(i), tCnt.getOrDefault(t.charAt(i), 0) + 1);
        }
        int ansL = -1, ansR = -1;
        int left = 0, right = 0;
        while (right < s.length()) {
            // 第一次for循环找满足t串的子串，除了移动right后check是否匹配，也可以遍历子串map tCnt来找到符合的right
            for (Map.Entry<Character, Integer> entry : tCnt.entrySet()) {
                char key = entry.getKey();
                int cnt = entry.getValue();
                int preCnt = windowCnt.getOrDefault(key, 0);
                cnt -= preCnt;
                while (cnt > 0) {
                    if (right >= s.length()) {
                        right = -1;
                        break;
                    }
                    char rCh = s.charAt(right);
                    if (rCh == key) {
                        cnt--;
                    }
                    windowCnt.put(rCh, windowCnt.getOrDefault(rCh, 0) + 1);
                    right++;
                }
                if (right == -1) {
                    break;
                }
            }
            if (right == -1) {
                break;
            }
            // 收缩左指针
            for (; left < right; left++) {
                char lCh = s.charAt(left);
                if (windowCnt.get(lCh).equals(tCnt.getOrDefault(lCh, -1))) {
                    break;
                }
                windowCnt.put(lCh, windowCnt.get(lCh) - 1);
            }
            // 找到窗口后判断是否最小距离，收缩left
            if (ansL == -1 || (ansR - ansL) > (right - left)) {
                ansL = left;
                ansR = right;
            }
            windowCnt.put(s.charAt(left), windowCnt.get(s.charAt(left)) - 1);
            left++;
        }
        if (ansL == -1) {
            return "";
        }
        return s.substring(ansL, ansR);
    }

    //方法一：滑动窗口
    Map<Character, Integer> ori = new HashMap<Character, Integer>();
    Map<Character, Integer> cnt = new HashMap<Character, Integer>();

    public String minWindow(String s, String t) {
        int tLen = t.length();
        for (int i = 0; i < tLen; i++) {
            char c = t.charAt(i);
            ori.put(c, ori.getOrDefault(c, 0) + 1);
        }
        int l = 0, r = -1;
        // 重点之一是维护ansL和ansR，找到最小子串
        int len = Integer.MAX_VALUE, ansL = -1, ansR = -1;
        int sLen = s.length();
        while (r < sLen) {
            ++r;
            if (r < sLen && ori.containsKey(s.charAt(r))) {
                cnt.put(s.charAt(r), cnt.getOrDefault(s.charAt(r), 0) + 1);
            }
            // 优化空间，收缩时的判断不用全判断，看收缩当前char的数量是不是等于t串中数量即可
            while (check() && l <= r) {
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    ansL = l;
                    ansR = l + len;
                }
                if (ori.containsKey(s.charAt(l))) {
                    cnt.put(s.charAt(l), cnt.getOrDefault(s.charAt(l), 0) - 1);
                }
                ++l;
            }
        }
        return ansL == -1 ? "" : s.substring(ansL, ansR);
    }

    public boolean check() {
        Iterator iter = ori.entrySet().iterator();
        while (iter.hasNext()) {
            Map.Entry entry = (Map.Entry) iter.next();
            Character key = (Character) entry.getKey();
            Integer val = (Integer) entry.getValue();
            if (cnt.getOrDefault(key, 0) < val) {
                return false;
            }
        }
        return true;
    }
}
