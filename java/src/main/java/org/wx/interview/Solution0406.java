package org.wx.interview;

import java.util.ArrayDeque;
import java.util.Deque;

public class Solution0406 {

    //Definition for a binary tree node.
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        Deque<TreeNode> stack = new ArrayDeque<>();
        TreeNode prev = null, curr = root;
        while (!stack.isEmpty() || curr != null) {
            while (curr != null) {
                stack.push(curr);
                curr = curr.left;
            }
            curr = stack.pop();
            if (prev == p) {
                return curr;
            }
            prev = curr;
            curr = curr.right;
        }
        return null;
    }

    public TreeNode inorderSuccessor2(TreeNode root, TreeNode p) {
        TreeNode successor = null;
        // 右子树存在，则后继节点为右子树的最左子节点
        if (p.right != null) {
            successor = p.right;
            while (successor.left != null) {
                successor = successor.left;
            }
            return successor;
        }
        TreeNode curr = root;
        // 利用二叉搜索树特性，大于则往左搜，直到curr为nul。实际不需要第一段代码，但考虑到第一段代码可以加速
        while (curr != null) {
            if (curr.val > p.val) {
                successor = curr;
                curr = curr.left;
            } else {
                curr = curr.right;
            }
        }
        return successor;
    }
}
