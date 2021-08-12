package org.wx.problems;

import java.util.*;

public class Solution0049 {
    public static void main(String[] args) {
        String[] strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
        Solution0049 solution = new Solution0049();
        List<List<String>> result = solution.groupAnagrams(strs);
        System.out.println(result);
    }

    /**
     * 49. Group Anagrams
     * java 字符串排序 map computeIfAbsent方法用法
     * 继续简化的方法就是排序后直接塞入map，见groupAnagrams2
     * 原C++做法采用26位字符数组合并为String为key来当此处的hashMap用，时间和空间效率都不占优
     */
    public List<List<String>> groupAnagrams(String[] strs) {
        String[] sort = Arrays.copyOf(strs, strs.length);
        for (int i = 0; i < sort.length; i++) {
            char[] arrayChar = sort[i].toCharArray();
            Arrays.sort(arrayChar);
            sort[i] = new String(arrayChar);
        }
        Map<String, List<String>> result = new HashMap<>();
        for (int i = 0; i < strs.length; i++) {
            result.computeIfAbsent(sort[i], k -> new ArrayList<>()).add(strs[i]);
        }
        return new ArrayList<>(result.values());
    }

    /**
     * 还可以继续用stream流处理得到hashmap
     */
    public List<List<String>> groupAnagrams2(String[] strs) {
        Map<String, List<String>> result = new HashMap<>();
        for (String str : strs) {
            char[] arrayChar = str.toCharArray();
            Arrays.sort(arrayChar);
            result.computeIfAbsent(new String(arrayChar), k -> new ArrayList<>()).add(str);
        }
        return new ArrayList<>(result.values());
    }
}
