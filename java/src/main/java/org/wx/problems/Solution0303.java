package org.wx.problems;

import java.util.Arrays;

public class Solution0303 {

}

/**
 * 303. Range Sum Query - Immutable
 */
class NumArray {
    int[] prefixSum;

    public NumArray(int[] nums) {
        this.prefixSum = Arrays.copyOf(nums, nums.length);
        for (int i = 1; i < nums.length; i++) {
            prefixSum[i] += prefixSum[i - 1];
        }
    }

    public int sumRange(int left, int right) {
        int leftSum = left == 0 ? 0 : this.prefixSum[left - 1];
        return this.prefixSum[right] - leftSum;
    }
}
