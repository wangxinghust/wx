package org.wx.problems;

import java.util.Deque;
import java.util.LinkedList;

/**
 * 105. 从前序与中序遍历序列构造二叉树
 */
public class Solution0105 {

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

    // 递归
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return buildTree(preorder, inorder, 0, preorder.length - 1, 0, inorder.length - 1);
    }

    public TreeNode buildTree(int[] preorder, int[] inorder, int l1, int r1, int l2, int r2) {
        if (l1 >= 0 && l1 <= r1 && r1 < preorder.length) {
            int val = preorder[l1];
            TreeNode node = new TreeNode(val);
            // 可以利用map缓存inorder，便于快速找index
            int index = l2;
            for (int i = l2; i <= r2; i++) {
                if (inorder[i] == val) {
                    index = i;
                    break;
                }
            }
            node.left = buildTree(preorder, inorder, l1 + 1, l1 + index - l2, l2, index - 1);
            node.right = buildTree(preorder, inorder, l1 + index - l2 + 1, r1, index + 1, r2);
            return node;
        }
        return null;
    }

    // 官解二：迭代，比较巧妙难记
    public TreeNode buildTree2(int[] preorder, int[] inorder) {
        if (preorder == null || preorder.length == 0) {
            return null;
        }
        TreeNode root = new TreeNode(preorder[0]);
        Deque<TreeNode> stack = new LinkedList<TreeNode>();
        stack.push(root);
        int inorderIndex = 0;
        for (int i = 1; i < preorder.length; i++) {
            int preorderVal = preorder[i];
            TreeNode node = stack.peek();
            if (node.val != inorder[inorderIndex]) {
                node.left = new TreeNode(preorderVal);
                stack.push(node.left);
            } else {
                while (!stack.isEmpty() && stack.peek().val == inorder[inorderIndex]) {
                    node = stack.pop();
                    inorderIndex++;
                }
                node.right = new TreeNode(preorderVal);
                stack.push(node.right);
            }
        }
        return root;
    }
}
