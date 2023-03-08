package org.wx.problems;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class Solution0257 {

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


    public List<String> binaryTreePaths(TreeNode root) {
        List<String> ans = new ArrayList<>();
        if (root.left == null && root.right == null) {
            ans.add(String.valueOf(root.val));
            return ans;
        }
        LinkedList<String> cur = new LinkedList<>();
        cur.add(String.valueOf(root.val));
        preOrder(root.left, cur, ans);
        preOrder(root.right, cur, ans);
        return ans;
    }

    private void preOrder(TreeNode node, LinkedList<String> cur, List<String> ans) {
        if (node == null) {
            return;
        }
        cur.add(String.valueOf(node.val));
        if (node.left == null && node.right == null) {
            ans.add(String.join("->", cur));
        }
        preOrder(node.left, cur, ans);
        preOrder(node.right, cur, ans);
        cur.removeLast();
    }
}
