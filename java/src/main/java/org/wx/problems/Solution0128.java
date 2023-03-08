package org.wx.problems;

import java.util.HashSet;
import java.util.Set;

/**
 * 128. 最长连续序列
 */
public class Solution0128 {
    public int longestConsecutive(int[] nums) {
        Set<Integer> numsSet = new HashSet<>();
        for (int num : nums) {
            numsSet.add(num);
        }

        int longest = 0;
        for (int num : numsSet) {
            // 利用前驱判断是不是连续序列的开头
            if (!numsSet.contains(num - 1)) {
                int curr = num;
                int currConsecutive = 1;
                while (numsSet.contains(curr + 1)) {
                    curr++;
                    currConsecutive++;
                }
                longest = Math.max(longest, currConsecutive);
            }
        }
        return longest;
    }
}
