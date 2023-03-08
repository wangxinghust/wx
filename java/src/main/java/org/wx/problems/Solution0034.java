package org.wx.problems;

import java.util.Arrays;

public class Solution0034 {
    public int[] searchRange(int[] nums, int target) {
        int[] ans = new int[2];
        Arrays.fill(ans, -1);
        if (nums.length == 0) {
            return ans;
        }
        ans[0] = searchRangeFirst(nums, target, 0, nums.length - 1);
        if (ans[0] == -1) {
            ans[1] = -1;
        } else {
            ans[1] = searchRangeLast(nums, target, ans[0], nums.length - 1);
        }
        return ans;
    }

    private int searchRangeFirst(int[] nums, int target, int left, int right) {
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (nums[right] == target) {
            return right;
        } else {
            return -1;
        }
    }

    private int searchRangeLast(int[] nums, int target, int left, int right) {
        while (left < right) {
            // 需要注意这里的+1处理，是为了取中后更靠近right，避免死循环
            int mid = (left + right + 1) / 2;
            if (nums[mid] <= target) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        if (nums[left] == target) {
            return left;
        } else {
            return -1;
        }
    }

    //官解
    public int[] searchRange2(int[] nums, int target) {
        int leftIdx = binarySearch(nums, target, true);
        int rightIdx = binarySearch(nums, target, false) - 1;
        if (leftIdx <= rightIdx && rightIdx < nums.length && nums[leftIdx] == target && nums[rightIdx] == target) {
            return new int[]{leftIdx, rightIdx};
        }
        return new int[]{-1, -1};
    }

    public int binarySearch(int[] nums, int target, boolean lower) {
        int left = 0, right = nums.length - 1, ans = nums.length;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target)) {
                right = mid - 1;
                ans = mid;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
}
