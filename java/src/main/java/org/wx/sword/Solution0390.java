package org.wx.sword;

/**
 * 1. hashMap
 * 2. 排序取中
 * 3. 投票法，以下为投票法，核心是要找得数字比其他数字出现次数之和要多，因此候选者+1，遇到不同数-1就一定能找到要的候选者
 */
public class Solution0390 {
    public int majorityElement(int[] nums) {
        int count = 0;
        Integer candidate = null;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
}
