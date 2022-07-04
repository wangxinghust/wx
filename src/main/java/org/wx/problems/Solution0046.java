package org.wx.problems;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Solution0046 {
    // 下一个排列方法求全排列
    public List<List<Integer>> permute(int[] nums) {
        Arrays.sort(nums);
        List<Integer> permutation = newList(nums);
        List<List<Integer>> ans = new ArrayList<>();
        ans.add(permutation);
        while ((permutation = nextPermutation(nums)) != null) {
            ans.add(permutation);
        }
        return ans;
    }

    private List<Integer> newList(int[] nums) {
        List<Integer> permutation = new ArrayList<>();
        for (int num : nums) {
            permutation.add(num);
        }
        return permutation;
    }

    private List<Integer> nextPermutation(int[] nums) {
        // 1. 第一个相邻小于的
        int left = nums.length - 2;
        while (left >= 0 && nums[left] >= nums[left + 1]) {
            left--;
        }
        // 2. 第一个大于left的
        if (left >= 0) {
            int right = nums.length - 1;
            while (right > left && nums[left] >= nums[right]) {
                right--;
            }
            // 3. swap
            swap(nums, left, right);
            // 4. reverse
            reverse(nums, left + 1);
            List<Integer> permutation = newList(nums);
            return permutation;
        }
        return null;
    }

    private void swap(int[] nums, int left, int right) {
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
    }

    private void reverse(int[] nums, int left) {
        int right = nums.length - 1;
        while (left <= right) {
            swap(nums, left++, right--);
        }
    }

    // 回溯法
    public List<List<Integer>> permute2(int[] nums) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();

        List<Integer> output = new ArrayList<Integer>();
        for (int num : nums) {
            output.add(num);
        }

        int n = nums.length;
        backtrack(n, output, res, 0);
        return res;
    }

    public void backtrack(int n, List<Integer> output, List<List<Integer>> res, int first) {
        // 所有数都填完了
        if (first == n) {
            res.add(new ArrayList<Integer>(output));
        }
        for (int i = first; i < n; i++) {
            // 动态维护数组
            Collections.swap(output, first, i);
            // 继续递归填下一个数
            backtrack(n, output, res, first + 1);
            // 撤销操作
            Collections.swap(output, first, i);
        }
    }
}
