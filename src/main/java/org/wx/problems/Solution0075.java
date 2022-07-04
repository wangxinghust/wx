package org.wx.problems;

import java.util.Arrays;

/**
 * 75. 颜色分类
 */
public class Solution0075 {
    public void sortColors(int[] nums) {
        // 三指针
        int red = -1, white = -1, blue = -1;

        for (int i = 0; i < nums.length; i++) {
            // 发现有一个0需要插入，则将2、1、0均往前移
            if (nums[i] == 0) {
                nums[++blue] = 2;
                nums[++white] = 1;
                nums[++red] = 0;
            } else if (nums[i] == 1) {
                nums[++blue] = 2;
                nums[++white] = 1;
            } else if (nums[i] == 2)
                nums[++blue] = 2;
        }
    }

    // 常规解法，三向划分，用交换
    public void sortColors2(int[] nums) {
        int red = 0, blue = nums.length - 1, idx = 0;
        // 注意这里是等于，因为blue指针指向的是blue颜色区的前一个位置
        while (idx <= blue) {
            if (nums[idx] == 0) {
                swap(nums, red++, idx++);
            } else if (nums[idx] == 2) {
                swap(nums, blue--, idx);
            } else {
                idx++;
            }
        }
    }

    private void swap(int[] nums, int l, int r) {
        int tmp = nums[l];
        nums[l] = nums[r];
        nums[r] = tmp;
    }

    public static void main(String[] args) {
        int[] nums = new int[]{2, 0, 2, 1, 1, 0};
        Solution0075 solution0075 = new Solution0075();
        solution0075.sortColors(nums);
        System.out.println(Arrays.toString(nums));
    }
}
