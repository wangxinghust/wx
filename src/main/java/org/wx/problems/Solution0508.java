package org.wx.problems;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Solution0508 {

    //Definition for a binary tree node.
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }


    int level;
    Map<Integer, Integer> sumCnt;

    public int[] findFrequentTreeSum(TreeNode root) {
        if (root == null) {
            return new int[0];
        }
        level = 0;
        sumCnt = new HashMap<Integer, Integer>();
        treeSum(root);
//        int sum = root.val + treeSum(root.left) + treeSum(root.right);
//        sumCnt.merge(sum, 1, (oldValue, newValue) -> oldValue + newValue);
//        level = Math.max(level, sumCnt.get(sum));
        List<Integer> res = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : sumCnt.entrySet()) {
            if (entry.getValue() == level) {
                res.add(entry.getKey());
            }
        }
        int[] ans = new int[res.size()];
        for (int i = 0; i < ans.length; i++) {
            ans[i] = res.get(i);
        }
        return ans;
    }

    private int treeSum(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int sum = root.val + treeSum(root.left) + treeSum(root.right);
        sumCnt.merge(sum, 1, Integer::sum);
        level = Math.max(level, sumCnt.get(sum));
        return sum;
    }
}
