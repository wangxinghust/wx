package org.wx.problems;

public class Solution0011 {
    public int maxArea(int[] height) {
        int maxArea = 0, left = 0, right = height.length - 1;
        while (left < right) {
            maxArea = Math.max(maxArea, (right - left) * Math.min(height[left], height[right]));
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }

    // 双指针，同上
    public int maxArea2(int[] height) {
        int left = 0, right = height.length - 1, maxArea = Math.min(height[left], height[right]) * (right - left);
        while (left < right) {
            if (height[left] <= height[right]) {
                left++;
            } else {
                right--;
            }
            maxArea = Math.max(maxArea, Math.min(height[left], height[right]) * (right - left));
        }
        return maxArea;
    }
}
