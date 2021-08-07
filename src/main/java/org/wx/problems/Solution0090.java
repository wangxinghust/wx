package org.wx.problems;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @author Wang Xing
 * @date 8/7/21
 */
public class Solution0090 {
    /**
     * 90. Subsets II
     * 2021-8-7 11:53:46
     * <p>
     * Approach by young_stone
     * The Basic idea is: use "while (i < n.length && n[i] == n[i - 1]) {i++;}" to avoid the duplicate. For example, the input is 2 2 2 3 4. Consider the helper function. The process is:
     * <p>
     * each.add(n[i]); --> add first 2 (index 0)
     * helper(res, new ArrayList<>(each), i + 1, n); --> go to recursion part, list each is <2 (index 0)>
     * while (i < n.length && n[i] == n[i - 1]) {i++;} --> after this, i == 3, add the element as in subset I
     */
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        // 先排序
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> each = new ArrayList<>();
        helper(res, each, 0, nums);
        return res;
    }

    public void helper(List<List<Integer>> res, List<Integer> each, int pos, int[] n) {
        if (pos <= n.length) {
            res.add(each);
        }
        int i = pos;
        while (i < n.length) {
            each.add(n[i]);
            helper(res, new ArrayList<>(each), i + 1, n);
            each.remove(each.size() - 1);
            i++;
            // 跳过重复
            while (i < n.length && n[i] == n[i - 1]) {
                i++;
            }
        }
        return;
    }
}
