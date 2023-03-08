package org.wx.problems;

import java.util.ArrayList;
import java.util.List;

/**
 * 95. Unique Binary Search Trees II
 */
public class Solution0095 {
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

    public static void main(String[] args) {
        Solution0095 solution = new Solution0095();
        List<TreeNode> nodes = solution.generateTrees2(3);
        System.out.println(nodes);
    }

    public List<TreeNode> generateTrees(int n) {
        List<TreeNode> nodes = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            List<TreeNode> lefts = generateTrees(1, i - 1);
            List<TreeNode> rights = generateTrees(i + 1, n);
            for (TreeNode left : lefts) {
                for (TreeNode right : rights) {
                    TreeNode node = new TreeNode(i);
                    node.left = left;
                    node.right = right;
                    nodes.add(node);
                }
            }
        }
        return nodes;
    }

    private List<TreeNode> generateTrees(int leftNum, int rightNum) {
        List<TreeNode> nodes = new ArrayList<>();
        if (leftNum > rightNum) {
            nodes.add(null);
            return nodes;
        }
        if (leftNum == rightNum) {
            nodes.add(new TreeNode(leftNum));
            return nodes;
        }
        for (int i = leftNum; i <= rightNum; i++) {
            List<TreeNode> lefts = generateTrees(leftNum, i - 1);
            List<TreeNode> rights = generateTrees(i + 1, rightNum);
            for (TreeNode left : lefts) {
                for (TreeNode right : rights) {
                    TreeNode node = new TreeNode(i);
                    node.left = left;
                    node.right = right;
                    nodes.add(node);
                }
            }
        }
        return nodes;
    }

    /**
     * 纯递归方式，无需在内层再写子方法逻辑
     */
    public List<TreeNode> generateTrees2(int n) {
        return generateTrees(1, n);
    }
}
