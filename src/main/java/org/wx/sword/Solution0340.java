package org.wx.sword;

import java.util.ArrayList;
import java.util.List;

public class Solution0340 {

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

    public List<List<Integer>> pathSum(TreeNode root, int target) {
        List<List<Integer>> res = new ArrayList<>();
        if (root == null) {
            return res;
        }
        dfs(root, target, res, new ArrayList<Integer>());
        return res;
    }

    private void dfs(TreeNode node, int target, List<List<Integer>> res, List<Integer> path) {
        if (node.left == null && node.right == null) {
            if (node.val == target) {
                path.add(node.val);
                List<Integer> newPath = new ArrayList<>(path);
                res.add(newPath);
                path.remove(path.size() - 1);
            }
        }
        if (node.left != null) {
            path.add(node.val);
            dfs(node.left, target - node.val, res, path);
            path.remove(path.size() - 1);
        }
        if (node.right != null) {
            path.add(node.val);
            dfs(node.right, target - node.val, res, path);
            path.remove(path.size() - 1);
        }
    }
}
