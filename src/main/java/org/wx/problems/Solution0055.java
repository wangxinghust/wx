package org.wx.problems;

public class Solution0055 {
    // 动态规划
    public boolean canJump(int[] nums) {
        boolean[] can = new boolean[nums.length];
        can[nums.length - 1] = true;
        for (int i = nums.length - 2; i >= 0; i--) {
            for (int j = i + 1; j <= i + nums[i] && j < nums.length; j++) {
                if (can[j]) {
                    can[i] = true;
                    break;
                }
            }
        }
        return can[0];
    }

    // 官解：贪心
    public boolean canJump2(int[] nums) {
        int n = nums.length;
        int rightmost = 0;
        for (int i = 0; i < n; ++i) {
            if (i <= rightmost) {
                rightmost = Math.max(rightmost, i + nums[i]);
                if (rightmost >= n - 1) {
                    return true;
                }
            }
        }
        return false;
    }
}
