package org.wx.problems;

public class Solution0153 {
    public int findMin(int[] nums) {
        int l = 0, r = nums.length - 1;
        if (nums[l] < nums[r]) {
            return nums[l];
        }
        while (l + 1 < r) {
            int mid = (l + r) >>> 1;
            if (nums[l] < nums[mid]) {
                l = mid;
            }
            if (nums[r] > nums[mid]) {
                r = mid;
            }
        }
        return nums[r];
    }
}
