package org.wx.sword;

public class Solution0030 {
    public int findRepeatNumber(int[] nums) {
        int[] cache = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            if (cache[nums[i]] != 0) {
                return nums[i];
            }
            cache[nums[i]]++;
        }
        return 0;
    }
}
