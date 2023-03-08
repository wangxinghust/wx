package org.wx.problems;

public class Solution1339 {

    //  Definition for a binary tree node.
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

    // 剪枝后依旧是超时
    public int maxProduct(TreeNode root) {
        long max = 0;
        long rootSum = sum(root);
        max = product(root, max, rootSum);
        max = max % 1000000007;
        return (int) max;
    }

    private long product(TreeNode root, long max, long rootSum) {
        if (root.left != null) {
            TreeNode left = root.left;
            root.left = null;
            long leftSum = sum(left);
            max = Math.max(max, leftSum * (rootSum - leftSum));
            root.left = left;
            // 剪枝
            if (leftSum > rootSum / 2) {
                max = Math.max(max, product(root.left, max, rootSum));
            }
        }
        if (root.right != null) {
            TreeNode right = root.right;
            root.right = null;
            long rightSum = sum(right);
            max = Math.max(max, rightSum * (rootSum - rightSum));
            root.right = right;
            if (rightSum > rootSum / 2) {
                max = Math.max(max, product(root.right, max, rootSum));
            }
        }
        return max;
    }

    private int sum(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return root.val + sum(root.left) + sum(root.right);
    }


    // approach by hiepit
    // 思路一致，重点在dfs遍历减少扫描次数
    long ans = 0, totalSum = 0;

    public int maxProduct2(TreeNode root) {
        totalSum = sum(root);
        dfs(root);
        return (int) (ans % (1e9 + 7));
    }

    private int dfs(TreeNode root) {
        if (root == null) return 0;
        int currSum = dfs(root.left) + dfs(root.right) + root.val;
        ans = Math.max(ans, (totalSum - currSum) * currSum);
        return currSum;
    }
}
