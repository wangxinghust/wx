package com.wx.leetcode219;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;

/**
 * @author Wang Xing
 * @date 8/21/20
 */
public class ContainsDuplicateII {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] nums = {1, 0, 1, 1};
        s.containsNearbyDuplicate(nums, 1);
    }
}

/**
 * 暴力解
 */
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        for (int i = Math.min(k, nums.length - 1); i > 0; i--) {
            for (int j = 0; j < nums.length - i; j++) {
                if (nums[j] == nums[j + i]) {
                    return true;
                }
            }
        }
        return false;
    }
}

/**
 * It iterates over the array using a sliding window.
 * The front of the window is at i, the rear of the window is k steps back.
 * The elements within that window are maintained using a Set.
 * While adding new element to the set, if add() returns false, it means the element already exists in the set.
 * At that point, we return true. If the control reaches out of for loop, it means that inner return true never executed,
 * meaning no such duplicate element was found.
 * 思路还是滑动窗口，用set存这个窗口的所有值，而不是暴力遍历1-k，在滑动过程中，set中的值有重复即说明true
 */
class Solution2 {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < nums.length; i++) {
            if (i > k) set.remove(nums[i - k - 1]);
            if (!set.add(nums[i])) return true;
        }
        return false;
    }
}
