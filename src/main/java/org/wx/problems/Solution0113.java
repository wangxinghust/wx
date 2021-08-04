package org.wx.problems;

import java.util.ArrayList;
import java.util.List;

/**
 * @author Wang Xing
 * @date 8/5/21
 */
public class Solution0113 {
    //Definition for a binary tree node.
    class TreeNode {
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

    /**
     * 113. Path Sum II
     * 2021-8-4 21:11:16
     */
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> result = new ArrayList<>();
        if (root == null) {
            return result;
        }
        recursivePath(root, targetSum, result, new ArrayList<Integer>(), 0);
        return result;
    }

    private void recursivePath(TreeNode node, int targetSum, List<List<Integer>> result, ArrayList<Integer> integers, int sum) {
        integers.add(node.val);
        if (node.left == null && node.right == null) {
            if (sum + node.val == targetSum) {
                List<Integer> copy = new ArrayList<>();
                for (Integer integer : integers) {
                    copy.add(integer);
                }
                result.add(copy);
            }
            integers.remove(integers.size() - 1);
            return;
        }
        if (node.left != null) {
            recursivePath(node.left, targetSum, result, integers, sum + node.val);
        }
        if (node.right != null) {
            recursivePath(node.right, targetSum, result, integers, sum + node.val);
        }
        integers.remove(integers.size() - 1);
    }
}


