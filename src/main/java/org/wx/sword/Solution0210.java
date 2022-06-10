package org.wx.sword;

public class Solution0210 {
    public int[] exchange(int[] nums) {
        int left = 0, right = nums.length - 1;
        while (left <= right) {
            if ((nums[left] & 1) == 0) {
                int tmp = nums[right];
                nums[right] = nums[left];
                nums[left] = tmp;
                right--;
            } else {
                left++;
            }
        }
        return nums;
    }
}
