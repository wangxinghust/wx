package org.wx.problems;

import java.util.HashSet;

public class Solution0653 {
    public static void main(String[] args) {
        //来源的数组
        Integer[] data = {2, 1, 3};
        //创建二叉树
        TreeNode treeNode = createTree(data, 0);
        Solution0653 solution = new Solution0653();
        boolean find = solution.findTarget(treeNode, 4);
        System.out.println(find);
    }

    private static TreeNode createTree(Integer[] array, int index) {
        TreeNode treeNode = null;
        if (index < array.length) {
            Integer value = array[index];
            if (value == null) {
                return null;
            }
            /*主要操作！！！*/
        /*采用递归方式，每次执行此方法，就会生成一个根节点和两个子节点a和b，
		同时子节点a再往下，创建属于a的子节点c和d，b也是同理。
		index为当前的下标。
		*/
            treeNode = new TreeNode(value);
            treeNode.left = createTree(array, 2 * index + 1);
            treeNode.right = createTree(array, 2 * index + 2);
            return treeNode;
        }
        return treeNode;
    }

    // Definition for a binary tree node.
    public static class TreeNode {
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

    private HashSet<Integer> valSet;

    public boolean findTarget(TreeNode root, int k) {
        valSet = new HashSet<>();
        return isEqualSum(root, k);
    }

    private boolean isEqualSum(TreeNode root, int k) {
        if (root == null) {
            return false;
        }
        if (valSet.contains(k - root.val)) {
            return true;
        }
        // System.out.println("当前值" + root.val + ", set集合是" + valSet.toString());
        valSet.add(root.val);
        return isEqualSum(root.left, k) || isEqualSum(root.right, k);
    }
}
