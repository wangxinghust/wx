package org.wx.problems;

import java.util.ArrayList;
import java.util.List;

public class Solution0039 {
    // 搜索回溯，不带剪枝
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> combination = new ArrayList<>();
        dfs(candidates, target, ans, combination, 0);
        return ans;
    }

    private void dfs(int[] candidates, int target, List<List<Integer>> ans, List<Integer> combination, int idx) {
        if (idx == candidates.length) {
            return;
        }
        if (target == 0) {
            ans.add(new ArrayList<>(combination));
            return;
        }
        // 直接跳过
        dfs(candidates, target, ans, combination, idx + 1);
        // 选择当前数
        if (target - candidates[idx] >= 0) {
            combination.add(candidates[idx]);
            dfs(candidates, target - candidates[idx], ans, combination, idx);
            combination.remove(combination.size() - 1);
        }
    }

    // 剪枝需对数组先排序
}
