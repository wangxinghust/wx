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

    // 排序+双指针比二分查找会快不少，复杂度更优
    public List<List<Integer>> threeSum2(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        for (int first = 0; first < nums.length - 2; first++) {
            // 注意此处的跳过重复枚举元素写法
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            int third = nums.length - 1;
            int target = -nums[first];
            for (int second = first + 1; second < nums.length - 1; second++) {
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                while (second < third && nums[second] + nums[third] > target) {
                    --third;
                }
                // 局部优化，考虑到结果都大于target，增大second还是同样的结果，可以break跳出
                if (second == third) {
                    break;
                }
                if (nums[second] + nums[third] == target) {
                    List<Integer> row = new ArrayList<>();
                    row.add(nums[first]);
                    row.add(nums[second]);
                    row.add(nums[third]);
                    res.add(row);
                }
            }
        }
        return res;
    }
}
