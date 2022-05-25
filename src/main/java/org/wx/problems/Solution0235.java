package org.wx.problems;

public class Solution0235 {

    //Definition for a binary tree node.
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        System.out.println(root.val);
        if (p.val > q.val) {
            return lowestCommonAncestor(root, q, p);
        }
        if (root.val < p.val && root.right != null) {
            return lowestCommonAncestor(root.right, p, q);
        }
        if (root.val > q.val && root.left != null) {
            return lowestCommonAncestor(root.left, p, q);
        }
        return root;
    }
}
