package org.wx.problems;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * 139. 单词拆分
 */
public class Solution0139 {
    // 递归，但超出时间限制
    public boolean wordBreak(String s, List<String> wordDict) {
        if (s.length() == 0) {
            return true;
        }
        for (String word : wordDict) {
            if (s.length() >= word.length() && s.substring(0, word.length()).equals(word)) {
                boolean res = wordBreak(s.substring(word.length()), wordDict);
                if (res) {
                    return true;
                }
            }
        }
        return false;
    }

    // 官解一：动态规划，不加剪枝优化
    // 递归不行，就上动态规划试试
    public boolean wordBreak2(String s, List<String> wordDict) {
        Set<String> wordDictSet = new HashSet(wordDict);
        boolean[] dp = new boolean[s.length() + 1];
        dp[0] = true;
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && wordDictSet.contains(s.substring(j, i))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
}
