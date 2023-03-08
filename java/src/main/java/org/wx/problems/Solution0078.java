package org.wx.problems;

import java.util.ArrayList;
import java.util.List;

/**
 * 78. 子集
 */
public class Solution0078 {
    // 搜过回溯
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        backtrack(nums, 0, ans, new ArrayList<>());
        return ans;
    }

    private void backtrack(int[] nums, int idx, List<List<Integer>> ans, List<Integer> sub) {
        if (idx == nums.length) {
            ans.add(new ArrayList<>(sub));
            return;
        }
        backtrack(nums, idx + 1, ans, sub);
        sub.add(nums[idx]);
        backtrack(nums, idx + 1, ans, sub);
        sub.remove(sub.size() - 1);
    }
}
