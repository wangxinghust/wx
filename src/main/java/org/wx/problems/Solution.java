package org.wx.problems;

import java.util.*;

//Definition for a binary tree node.
class TreeNode {
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

/**
 * @author Wang Xing
 * @date 8/4/21
 */
public class Solution {

    /**
     * 113. Path Sum II
     * 2021-8-4 21:11:16
     */
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> result = new ArrayList<>();
        if (root == null) {
            return result;
        }
        recursivePath(root, targetSum, result, new ArrayList<Integer>(), 0);
        return result;
    }

    private void recursivePath(TreeNode node, int targetSum, List<List<Integer>> result, ArrayList<Integer> integers, int sum) {
        integers.add(node.val);
        if (node.left == null && node.right == null) {
            if (sum + node.val == targetSum) {
                List<Integer> copy = new ArrayList<>();
                for (Integer integer : integers) {
                    copy.add(integer);
                }
                result.add(copy);
            }
            integers.remove(integers.size() - 1);
            return;
        }
        if (node.left != null) {
            recursivePath(node.left, targetSum, result, integers, sum + node.val);
        }
        if (node.right != null) {
            recursivePath(node.right, targetSum, result, integers, sum + node.val);
        }
        integers.remove(integers.size() - 1);
    }

    /**
     * 174. Dungeon Game
     * 2021-8-4 23:09:36
     */
    public int calculateMinimumHP(int[][] dungeon) {
        int m = dungeon.length;
        int n = dungeon[0].length;
        int[][] data = new int[m][n];
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) {
                    data[i][j] = -dungeon[i][j];
                } else if (i == m - 1) {
                    data[i][j] = data[i][j + 1] - dungeon[i][j];
                } else if (j == n - 1) {
                    data[i][j] = data[i + 1][j] - dungeon[i][j];
                } else {
                    data[i][j] = Integer.min(i == m - 1 ? 0 : data[i + 1][j], j == n - 1 ? 0 : data[i][j + 1]) - dungeon[i][j];
                }
                data[i][j] = Integer.max(data[i][j], 0);
            }
        }
        return data[0][0] + 1;
    }

    /**
     * 228. Summary Ranges
     * 2021-8-4 01:06:30
     */
    public List<String> summaryRanges(int[] nums) {
        if (nums.length == 0) {
            return new ArrayList<>();
        }
        List<String> result = new LinkedList<>();
        int left = nums[0], right = nums[0];
        for (int i = 0; i < nums.length; i++) {
            if (i + 1 >= nums.length) {
                if (left == right) {
                    result.add(String.valueOf(left));
                } else {
                    result.add(left + "->" + right);
                }
                break;
            }


            if (nums[i + 1] == right + 1) {
                right = nums[i + 1];
            } else {
                if (left == right) {
                    result.add(String.valueOf(left));
                } else {
                    result.add(left + "->" + right);
                }
                left = right = nums[i + 1];
            }
        }
        return result;
    }
}
