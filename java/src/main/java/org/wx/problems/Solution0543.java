package org.wx.problems;

public class Solution0543 {

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

    class Solution {
        private int longestPath = 0;

        public int diameterOfBinaryTree(TreeNode root) {
            diameter(root);
            return longestPath;
        }

        private int diameter(TreeNode root) {
            if (root == null) return 0;
            int left_height = diameter(root.left);
            int right_height = diameter(root.right);
            longestPath = Math.max(longestPath, left_height + right_height);
            return Math.max(left_height, right_height) + 1;
        }
    }
}
