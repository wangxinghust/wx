package org.wx.problems;

import java.util.ArrayList;
import java.util.List;

public class Solution0993 {

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


    public boolean isCousins(TreeNode root, int x, int y) {
        if (root == null || root.val == x || root.val == y) {
            return false;
        }
        List<TreeNode> layer = new ArrayList<>();
        layer.add(root);
        while (layer.size() > 0) {
            boolean find = false;
            List<TreeNode> tmp = new ArrayList<>();
            for (int i = 0; i < layer.size(); i++) {
                TreeNode node = layer.get(i);
                if (node.val == x || node.val == y) {
                    if (find) {
                        return true;
                    } else {
                        find = true;
                    }
                }
                if (node.left != null) {
                    tmp.add(node.left);
                }
                if (node.right != null) {
                    tmp.add(node.right);
                }
                if (node.left != null && node.right != null) {
                    if ((node.left.val == x || node.left.val == y) && (node.right.val == x || node.right.val == y)) {
                        return false;
                    }
                }
            }
            if (find) {
                return false;
            }
            layer = tmp;
        }
        return false;
    }

    private int dx = -1, dy = -1, xPar = -1, yPar = -1;

    public boolean isCousins2(TreeNode root, int x, int y) {
        rec(root, x, y, 0, -1);
        return dx == dy && xPar != yPar;
    }

    private void rec(TreeNode node, int x, int y, int depth, int parent) {
        if (node == null) {
            return;
        }
        if (node.val == x) {
            dx = depth;
            xPar = parent;
        }
        if (node.val == y) {
            dy = depth;
            yPar = parent;
        }
        if (dx != -1 && dy != -1) {
            return;
        }

        rec(node.left, x, y, depth + 1, node.val);
        rec(node.right, x, y, depth + 1, node.val);
    }
}
