package org.wx.problems;

public class Solution0033 {
    // 二分查找，利用旋转后部分数组依然有序的方式来二分
    public int search(int[] nums, int target) {
        int n = nums.length;
        if (n == 0) {
            return -1;
        }
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            // 前半段有序，这里是小于等于，比较重要，否则通不过[3,1] 1用例
            if (nums[0] <= nums[mid]) {
                // 前半段有序，且刚好target在0-mid区间，那可以缩小范围，否则就在另一边
                if (nums[0] <= target && nums[mid] > target) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[n - 1] >= target && nums[mid] < target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
}
