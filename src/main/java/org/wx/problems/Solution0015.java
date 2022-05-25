package org.wx.problems;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution0015 {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        int len = nums.length;
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < len; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < len; j++) {
                if (j != i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int value = -nums[i] - nums[j];
                if (value < nums[j] || value > nums[len - 1]) {
                    continue;
                }
                int index = Arrays.binarySearch(nums, j + 1, len, value);
                if (index >= j + 1) {
                    List<Integer> row = new ArrayList<>();
                    row.add(nums[i]);
                    row.add(nums[j]);
                    row.add(nums[index]);
                    ans.add(row);
                }
            }
        }
        return ans;
    }
}
