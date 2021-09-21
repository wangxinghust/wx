package org.wx.problems;

/**
 * 485. Max Consecutive Ones
 */
public class Solution0485 {
    public int findMaxConsecutiveOnes(int[] nums) {
        int len = 0, cnt = 0;
        for (int i = 0; i <= nums.length; i++) {
            if (i == nums.length || nums[i] != 1) {
                len = Math.max(len, cnt);
                cnt = 0;
            } else {
                cnt++;
            }
        }
        return len;
    }
}
