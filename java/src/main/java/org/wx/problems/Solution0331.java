package org.wx.problems;

/**
 * 331. Verify Preorder Serialization of a Binary Tree
 */
public class Solution0331 {
    public boolean isValidSerialization(String preorder) {
        String[] nums = preorder.split(",");
        int node = 1;
        for (String num : nums) {
            node--;
            if (node < 0) {
                return false;
            }
            if (!"#".equals(num)) {
                node += 2;
            }
        }
        return node == 0;
    }
}
