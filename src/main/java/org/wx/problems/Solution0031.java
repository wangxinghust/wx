package org.wx.problems;

public class Solution0031 {
    // 下一个排列
    public void nextPermutation(int[] nums) {
        //1. 从后往前找第一个小于后者的数
        int left = nums.length - 2;
        while (left >= 0 && nums[left] >= nums[left + 1]) {
            left--;
        }
        //2. 从后往前找第一个大于left的数
        int right = nums.length - 1;
        while (left >= 0 && right >= 0 && nums[left] >= nums[right]) {
            right--;
        }
        //3. 交换
        if (left >= 0) {
            swap(nums, left, right);
        }
        //4. 反转
        reverse(nums, left);
    }

    private void swap(int[] nums, int left, int right) {
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
    }

    private void reverse(int[] nums, int left) {
        left++;
        int right = nums.length - 1;
        while (left <= right) {
            swap(nums, left++, right--);
        }
    }
}
