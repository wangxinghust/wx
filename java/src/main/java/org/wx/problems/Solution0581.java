package org.wx.problems;

/**
 * 581. 最短无序连续子数组
 */
public class Solution0581 {
    public int findUnsortedSubarray(int[] nums) {
        int left = Integer.MAX_VALUE, leftIdx = 0;
        int right = Integer.MIN_VALUE, rightIdx = nums.length - 1;
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                if (nums[i + 1] < left) {
                    left = nums[i + 1];
                    leftIdx = i + 1;
                }
                if (nums[i] > right) {
                    right = nums[i];
                    rightIdx = i;
                }
            }
        }
        if (left == Integer.MAX_VALUE) {
            return 0;
        }
        int x = 0;
        for (; x < leftIdx; x++) {
            if (nums[x] > left) {
                break;
            }
        }
        int y = nums.length - 1;
        for (; y > rightIdx; y--) {
            if (nums[y] < right) {
                break;
            }
        }
        return y - x + 1;
    }

    //方法二：一次遍历，思路一致，标记不同，且在一次循环中完成
    public int findUnsortedSubarray2(int[] nums) {
        int n = nums.length;
        int maxn = Integer.MIN_VALUE, right = -1;
        int minn = Integer.MAX_VALUE, left = -1;
        for (int i = 0; i < n; i++) {
            if (maxn > nums[i]) {
                right = i;
            } else {
                maxn = nums[i];
            }
            if (minn < nums[n - i - 1]) {
                left = n - i - 1;
            } else {
                minn = nums[n - i - 1];
            }
        }
        return right == -1 ? 0 : right - left + 1;
    }
}
