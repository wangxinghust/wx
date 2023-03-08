package org.wx.problems;

import java.util.Stack;

/**
 * 98. 验证二叉搜索树
 */
public class Solution0098 {
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

    // 中序遍历+判断
    public boolean isValidBST(TreeNode root) {
        Stack<TreeNode> stack = new Stack<>();
        //Deque<TreeNode> stack = new LinkedList<TreeNode>();
        TreeNode node = root, cur = null, pre = null;
        while (node != null || !stack.isEmpty()) {
            while (node != null) {
                stack.push(node);
                node = node.left;
            }
            if (!stack.isEmpty()) {
                node = stack.pop();
                pre = cur;
                cur = node;
                if (pre != null && pre.val >= cur.val) {
                    return false;
                }
                node = node.right;
            }
        }
        return true;
    }

    // 官解一：纯递归
    public boolean isValidBST2(TreeNode root) {
        return isValidBST(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }

    public boolean isValidBST(TreeNode node, long lower, long upper) {
        if (node == null) {
            return true;
        }
        if (node.val <= lower || node.val >= upper) {
            return false;
        }
        return isValidBST(node.left, lower, node.val) && isValidBST(node.right, node.val, upper);
    }
}
