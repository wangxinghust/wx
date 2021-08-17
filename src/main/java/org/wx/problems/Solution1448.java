package org.wx.problems;

public class Solution1448 {
    // Definition for a binary tree node.
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
     * Count Good Nodes in Binary Tree
     */
    public int goodNodes(TreeNode root) {
        return isGoodNodes(root, Integer.MIN_VALUE);
    }

    int isGoodNodes(TreeNode root, int max) {
        if (root == null) {
            return 0;
        }
        if (root.val >= max) {
            return 1 + isGoodNodes(root.left, root.val) + isGoodNodes(root.right, root.val);
        } else {
            return isGoodNodes(root.left, max) + isGoodNodes(root.right, max);
        }
    }
}
